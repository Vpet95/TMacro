#ifndef NATIVE
/* Non-native options */
#pragma WIDE
#pragma XMEM
#pragma NOMAP
#pragma NOOLDCALLS
#pragma LARGESYM
#pragma SYMBOLS
#pragma INSPECT
#pragma HIGHPIN         /* tfr */
#pragma SAVEABEND
#pragma NOCHECK  /* (NOCHECK to test performance) */
#endif

/* 
COPYRIGHT GRAVIC, INC. 1995 - 2007
All Rights Reserved.

*** CONFIDENTIAL AND PROPRIETARY PROPERTY OF GRAVIC, INC.  ***

Usage of this source code is provided to customers solely under the terms
of a valid license agreement from Gravic, Inc..  ALL OTHER USERS ARE STRICTLY
FORBIDDEN AND MAY CONSTITUTE THEFT OF TRADE SECRETS OR OTHER SERIOUS CRIME,
AND WILL BE PROSECUTED TO THE FULLEST EXTENT OF THE LAW!

NOTICE: This, and all copies of this software and documentation,
must be returned to Gravic, Inc. or destroyed upon termination of
the valid license. If you find a copy outside of the terms
of a valid license agreement, please notify our office and immediately return
copy to Gravic, Inc. or destroy!

Gravic, Inc. will a provide a $5000 reward for the arrest and conviction of
anyone stealing this software. Report all occurrences to:
President
Gravic, Inc.
301 Lindenwood Dr.
Malvern, PA 19355-1758 USA
(610) 647-6250

All copies of this software in all such forms, and derivatives thereof,
must carry this entire notice.

Any documentation about software incorporating or using such forms must
contain these notices and any advertising about such software must
acknowledge that the software contains elements which are the property
of Gravic, Inc., used under license.

The name and trademarks of Gravic, Inc. may not be otherwise used
without the expressed, written permission of Gravic, Inc..

EXCLUSION OF WARRANTY AND LIMITATION OF LIABILITY:
THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED
WARRANTIES INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. TO THE MAXIMUM
EXTENT PERMITTED BY LAW, IN NO EVENT SHALL GRAVIC, INC. ITS OFFICERS,
DIRECTORS, EMPLOYEES, ADVISORS, SUPPLIERS, OR LICENSORS BE LIABLE FOR ANY
DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, CONSEQUENTIAL OR
SPECIAL DAMAGES OR DAMAGES FOR LOSS OF PROFITS, INTERRUPTION OF BUSINESS,
LOSS OR RECONSTRUCTION OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS)
ARISING OUT OF OR IN CONNECTION WITH USE OF OR INABILITY TO USE THE
SOFTWARE, EVEN IF GRAVIC, INC. HAS BEEN ADVISED OF THE POSSIBILITY OF
SUCH DAMAGES. Some jurisdictions do not permit the exclusion or limitation
for certain damages, so the above may not apply to you.

All questions about this notice may be made to the above address.
*/


/** 
* @file W:\nsb\trunk\dev\shadowbase\Type101\vector.c
*
* Implementation for a growable vector.
*
* @author John Hoffmann
*/


#ifdef _lint
#define LINT_LEVEL 1

#include "include/lint_er.h"
#endif

#ifdef NATIVE
#include "include/vector.h"
#else
#include "vectorh"
#endif

#include <stdlib.h>

static VECTOR_CMP_FUNC compare_function;



/** For non-native compiling only, this function wraps the realloc 
* function so that it can be passed to vector_create.
*/
void *vector_nn_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
} 

/** For non-native compiling only, this function wraps the free 
* function so that it can be passed to vector_create.
*/
void vector_nn_free(void *ptr)
{
    free(ptr);
}

/** Compare function wrapper. The sort and bsearch functions pass in pointers
* to the things that are being compared. In this case, the things that are being 
* compared are void * elements, so we are actually getting a void **ptr. This needs
* to be dereferenced for the user's compare function.
*/
static int compare(const void *ptr1, const void *ptr2)
{
    const void **ptr1ptr = (const void **)ptr1;
    const void **ptr2ptr = (const void **)ptr2;
    return compare_function(*ptr1ptr, *ptr2ptr);
}

static void reserve(VECTOR *v, size_t new_size)
{
    while (v->allocated < new_size)
    {
        v->elements = v->alloc_func(v->elements, new_size * sizeof(void *));
        v->allocated = new_size;
    }
}


VECTOR *vector_create(size_t initial_size, 
                      size_t alloc_incr, 
                      VECTOR_ALLOC_FUNC alloc_func, 
                      VECTOR_FREE_FUNC free_func )
{
    VECTOR *new_vector;
    if (alloc_func != NULL)
        new_vector = alloc_func(NULL, sizeof(VECTOR));
    else
        new_vector = malloc(sizeof(VECTOR));

    if (new_vector != NULL)
    {
        new_vector->alloc_incr = alloc_incr;
        new_vector->allocated = 0;
        new_vector->size = 0;
        new_vector->elements = NULL;
        if (alloc_func != NULL)
            new_vector->alloc_func = alloc_func;
        else 
            new_vector->alloc_func = REALLOC;
        new_vector->free_func = free_func;
        reserve(new_vector, initial_size);
    }
    return new_vector;
}

size_t vector_size(const VECTOR *v)
{
    return v->size;
}

void *vector_get(VECTOR *v, size_t index)
{
    if (index < v->size)
        return v->elements[index];
    else
        return NULL;
}   /*lint !e818   Pointer parameter 'v' (line 125) could be declared as pointing to const (why? return ptr is not const) */

/** Sets the element at the index passed in to the ptr. If the free function 
* was specified, the existing pointer at the element will be freed and NULL will
* be returned. Otherwise, the existing pointer will be returned and it is the 
* caller's responsibility to free the memory. If the index is beyond the end of the vector,
* the vector will be expanded to include the elements, all pointers between
* the previous end of the vector and the new pointer will be set to NULL.
*/
void *vector_set(VECTOR *v,                 /*!< the vector */
                 void *new_element,         /*!< the new element */
                 size_t index               /*!< the index */
                 )
{
    size_t i;
    void *ptr;
    if (index >= v->size)
    {
        i = v->size;
        reserve(v, index+1);
        for (;i<=index;++i)
            v->elements[i] = NULL;
        v->size = index+1;
    }

    ptr = v->elements[index];
    v->elements[index] = new_element;
    if ( (ptr != NULL) && (v->free_func != NULL))
    {
        v->free_func(ptr);
        return NULL;
    }
    return ptr;


}


void *vector_back(VECTOR *v)
{
    if (v->size > 0)
        return v->elements[v->size-1];
    else
        return NULL;
}   /*lint !e818   Pointer parameter 'v' (line 125) could be declared as pointing to const (why? return ptr is not const) */

void vector_pop_back(VECTOR *v)
{
    if (v->size > 0)
    {
        v->size--;
        if (v->free_func != NULL)
            v->free_func(v->elements[v->size]);
    }
}

void vector_insert(VECTOR *v, void *element, size_t index)
{
    if (v->size==v->allocated)
        reserve(v, v->allocated+v->alloc_incr);

    if (index >= v->size)
    {
        v->elements[v->size] = element;
    }
    else
    {
        memmove(&v->elements[index+1], &v->elements[index], (v->size-index)*sizeof(void *));
        v->elements[index] = element;
    }
    v->size++;
}

void vector_push_back(VECTOR *v, void *element)
{
    if (v->size==v->allocated)
        reserve(v, v->allocated+v->alloc_incr);
    v->elements[v->size] = element;
    v->size++;
}

void vector_remove(VECTOR *v, size_t index)
{
    if (index < v->size)
    {
        size_t num_to_move = (v->size - index) - 1;
        if (v->free_func != NULL)
            v->free_func(v->elements[index]);
        if (num_to_move > 0)
        {
            memmove(&v->elements[index], &v->elements[index+1], num_to_move * sizeof(void *));
        }
        v->size -= 1;
    }
}

void vector_destroy(VECTOR *v)
{
    vector_empty(v);
    v->alloc_func(v->elements, 0);
    v->alloc_func(v, 0);

}

void vector_sort(VECTOR *v, VECTOR_CMP_FUNC compare_func)
{
    if (v->size > 1)
    {
        compare_function = compare_func;
        qsort(v->elements, v->size, sizeof(void *), compare);
    }
}   /*lint !e818   Pointer parameter 'v' (line 125) could be declared as pointing to const (why? contents are reordered) */

void *vector_search(VECTOR *v, void *key, VECTOR_CMP_FUNC compare_func)
{
    void *result;
    compare_function = compare_func;
    result = bsearch(&key,      /* needs to be converted to a void ** */
                     v->elements,
                     v->size,
                     sizeof(void *),
                     compare);
    if (result != NULL)
    {
        /* result is really a pointer to a void pointer */
        void **vpp = (void **)result;
        return *vpp; 
    }
    else
        return NULL;
}   /*lint !e818   Pointer parameter 'v' (line 125) could be declared as pointing to const (why? return ptr is not const) */


void *vector_scan(VECTOR *v, const void *key, size_t *index, VECTOR_CMP_FUNC compare_func)
{
    return vector_scan_from(v, key, 0, index, compare_func);
}


void *vector_scan_from(VECTOR *v, const void *key, size_t start_index, size_t *index, VECTOR_CMP_FUNC compare_func)
{
    size_t i;
    for (i=start_index; i<v->size; ++i)
    {
        if (compare_func(key, v->elements[i])==0)
        {
            if (index != NULL)
                *index = i;
            return v->elements[i];
        }
    }
    if (index != NULL)
        *index = v->size;
    return NULL;
}   /*lint !e818  pointer parameter 'v' (line 275) could be declared as pointing to const */
    /*note - causes error in non-native compiles. */

void vector_empty(VECTOR *v)
{
    if ((v->free_func != NULL) && (v->size > 0))
    {
        size_t i;
        for (i=0; i< v->size; i++)
            v->free_func(v->elements[i]);
    }
    v->size = 0;
}

void vector_reserve(VECTOR *v, size_t new_alloc_size)
{
    if (v->allocated < new_alloc_size)
    {
        reserve(v, new_alloc_size);
    }
}


void vector_push_copy(VECTOR *v, const void *element_to_copy, size_t element_size)
{
    void *ptr = NULL;
    ptr = v->alloc_func(ptr, element_size);
    memcpy(ptr, element_to_copy, element_size);
    vector_push_back(v, ptr);
}

void vector_insert_copy(VECTOR *v, const void *element_to_copy,
                        size_t element_size, size_t insert_at)    
{
    void *ptr = NULL;
    ptr = v->alloc_func(ptr, element_size);
    memcpy(ptr, element_to_copy, element_size);
    vector_insert(v, ptr, insert_at);
}



void* vector_set_copy(VECTOR *v, 
                     const void *element_to_copy,
                     size_t element_size, 
                     size_t set_at)    
{
    void *ptr = NULL;
    ptr = v->alloc_func(ptr, element_size);
    memcpy(ptr, element_to_copy, element_size);
    return vector_set(v, ptr, set_at);
}


