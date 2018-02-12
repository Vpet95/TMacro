
#ifndef COMMON_VECTOR_H
#define COMMON_VECTOR_H

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
* @file W:\nsb\trunk\dev\shadowbase\Type101\vector.h
*
* Definition for a growable vector of pointers.
*
* @author John Hoffmann
*/


#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



/** Typedef for a comparison function pointer used in vector_search, vector_sort
*
* The compare function should return 0 if left == right; <0 if left < right; and >0 if left > right.
*/
typedef int (*VECTOR_CMP_FUNC)(const void *left, const void *right);

/** Typedef for a function to free a pointer. 
*/
typedef void (*VECTOR_FREE_FUNC)(void *ptr);

/** Typedef for a function to be called for to allocate memory. Should have the same
* characteristics as REALLOC - if NULL passed in, allocate memory. If size is 0,
* delete memory.
*/
typedef void *(*VECTOR_ALLOC_FUNC)(void *ptr, size_t new_size);

/** Structure of a vector.
*/
typedef struct
{
    void **elements;            /*!< pointer to a growable array of element pointers */
    size_t allocated;           /*!< number of allocated elements */
    size_t alloc_incr;          /*!< amt to increate allocation by */
    size_t size;                /*!< current size */
    VECTOR_ALLOC_FUNC alloc_func;                 /*!< function to be called to allocate space (REALLOC) */
    VECTOR_FREE_FUNC free_func ;                  /*!< function pointer for freeing removed elements. */
} VECTOR;

/**  Defines for the free function. The non-native version of free does not 
* match the prototype - it is actually a TAL function and has different attributes that
* causes warnings when passed into vector methods. The define, for native compilers, 
* resolves to free. For the non-native compilers, it resolves to vector_nn_free, which
* wraps the free call.
*/
#ifdef NATIVE
#define REALLOC realloc
#define FREE free
#else
#define REALLOC vector_nn_realloc
#define FREE vector_nn_free
#endif /*non-native */

/** For non-native compiling only, wraps free in a VECTOR_FREE_FUNC compatible call.
* The non-native version generates warning, you can avoid them by specifying FREE (in caps)
* as the free function if you are using standard memory allocation / free for elements.  FREE
* will just use free for NATIVE compiles, and will use vector_nn_free for non-native compiles.
*/
void vector_nn_free(void *ptr);  

/** For non-native compiling only, wraps realloc in a VECTOR_REALLOC_FUNC compatible call.
* The non-native version generates warning, you can avoid them by specifying REALLOC (in caps)
* as the realloc function if you are using standard memory allocation / free for elements. REALLOC
* will just use realloc for NATIVE compiles, and will use vector_nn_realloc for non-native compiles.
*/
void *vector_nn_realloc(void *ptr, size_t new_size);



/** Creates a vector. 
*
* Notes: if the free_fp is null, elements will not be destroyed when they are removed
* from the vector (vector_remove, vector_pop_last, vector_destroy). If it is not null,
* it will be called to free the pointers. You can specify free() as the pointer.
*/
VECTOR* vector_create(size_t initial_size,  /*!< number of elements to be initially allocated) */
                      size_t alloc_incr,    /*!< amount to increase the allocation by when space is exhausted */
                      VECTOR_ALLOC_FUNC alloc_func, /*!< function to be called to allocate space for vector. If NULL, realloc is used. */
                      VECTOR_FREE_FUNC free_func    /*!< function to call to free elements when removed. If NULL, they are not freed */
                      );

/** Returns the number of elements in the vector.
*/
size_t vector_size(const VECTOR *v);

/** Returns a pointer to the ith element. Will be NULL if beyond the end.
*/
void *vector_get(VECTOR *v,                  /*!< the vector */
                 size_t index);              /*!< index of pointer to fetch, 0 relative */

/** Returns a pointer to the last element. Will be NULL if empty
*/
void *vector_back(VECTOR *v);                  /*!< the vector */

/** Sets the element at the index passed in to the ptr. If the free function 
* was specified, the existing pointer at the element will be freed and NULL will
* be returned. Otherwise, the existing pointer will be returned and it is the 
* caller's responsibility to free the memory. If the index is beyond the end of the vector,
* the vector will be expanded to include the elements, all pointers between
* the previous end of the vector and the new pointer will be set to NULL.
*/
void *vector_set(VECTOR *v,                 /*!< the vector */
                 void *ptr,                 /*!< the value to set */
                 size_t index               /*!< the index */
                 );


/** Removes the last element, calling the free function if specified in vector_create()
*/
void vector_pop_back(VECTOR *v);                 /*!< the vector */

/** Inserts the element at the specified position, pushing all others back. If
* index >= the size, the element will be at the end.
*/
void vector_insert(VECTOR *v, void *element, size_t index);

/** Inserts the element at the end of the vector.
*/
void vector_push_back(VECTOR *v, void *element);

/** Removes the ith element, call the free function if specified in vector_create(). 
*/
void vector_remove(VECTOR *v,                  /*!< the vector */
                    size_t index);              /*!< the index of the item to remove. */

/** Frees the vector. If a free function was specified in vector_create() and there are
* elements in the vector, they will be freed as well.
*/
void vector_destroy(VECTOR *v);                  /*!< the vector */


/** Reserves the specified number of elements. 
*/
void vector_reserve(VECTOR *v,                  /*!< the vector */
                    size_t elements);           /*!< space to reserve */

/** Sorts the vector.
*/
void vector_sort(VECTOR *v,                     /*!< the vector to sort. */
                 VECTOR_CMP_FUNC compare);      /*!< the comparison function */

/** Searchss the vector using a binary search. Vector must be sorted.
*
* @return pointer to matching entry, or null if none match.
*/
void *vector_search(VECTOR *v,                   /*!< the vector to search */
                    void *key,                   /*!< the key to search for */
                    VECTOR_CMP_FUNC compare);    /*!< the comparison function */

/** Scans the vector until a match is found. Vector does not need to be sorted.
* @return pointer to matching entry, or null if none match.
*/
void *vector_scan(VECTOR *v,                    /*!< the vector to search */
                  const void *key,              /*!< the key to search for */
                  size_t *index,                /*!< (I/O) the index of the entry, or vector_size(v) if not found. Optional
                                                         parameter, will be ignored if NULL) */
                  VECTOR_CMP_FUNC compare);     /*< the comparison function. */

/** Scans the vector from the index specified until a match is found. Vector does not need to be sorted.
* @return pointer to matching entry, or null if none match. This function may be repeatedly called
* to return all matching items.
*/     
void *vector_scan_from(VECTOR *v,                    /*!< the vector to search */
                       const void *key,              /*!< the key to search for */
                       size_t start_index,           /*!< the start index */
                       size_t *index,                /*!< (I/O) the index of the entry, or vector_size(v) if not found. Optional
                                                           parameter, will be ignored if NULL) */
                       VECTOR_CMP_FUNC compare);     /*< the comparison function. */



/** Empties the vector - the vector remains allocated, but all elements are removed.
*/
void vector_empty(VECTOR *v);                  /*!< the vector to empty */

/** Pushes a copy of the element on the vector. Note: if vector_push_copy is used,
* the copy will be allocated using the realloc function pointer passed in when
* the vector is created. To avoid memory leaks and traps, the free function pointer should
* point to a function to deallocate memory allocated by the realloc function ptr.
*/
void vector_push_copy(VECTOR *v, const void *element_to_copy, size_t element_size);

/** Inserts a copy of the element on the vector. Note: if vector_insert_copy is used,
* the copy will be allocated using the realloc function pointer passed in when
* the vector is created. To avoid memory leaks and traps, the free function pointer should
* point to a function to deallocate memory allocated by the realloc function ptr.
*/
void vector_insert_copy(VECTOR *v, const void *element_to_copy, size_t element_size, size_t insert_at);
  
/** Sets a copy of th element at the index passed in to the ptr. If the free function 
* was specified, the existing pointer at the element will be freed and NULL will
* be returned. Otherwise, the existing pointer will be returned and it is the 
* caller's responsibility to free the memory. If the index is beyond the end of the vector,
* the vector will be expanded to include the elements, all pointers between
* the previous end of the vector and the new pointer will be set to NULL.
*
* Note: if vector_set_copy is used,the copy will be allocated using the realloc 
* function pointer passed in when the vector is created. To avoid 
* memory leaks and traps, the free function pointer should
* point to a function to deallocate memory allocated by the realloc function ptr.
*/
void* vector_set_copy(VECTOR *v, 
                      const void *element_to_copy,
                      size_t element_size, 
                      size_t set_at);


#ifdef __cplusplus
}	// extern "C"
#endif



#endif /* COMMON_VECTOR_H */
