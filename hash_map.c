
#include <stdlib.h>
#include <stdio.h>

#include "include/util.h"
#include "include/hash_map.h"

#define TOTAL_INTERNAL_BUCKET_SIZE 127

typedef struct MetadataMap {
	unsigned long key; /* the map's unique pointer address */

	map_t map;

	int max_bucket_size; /* the map's total bucket size */

	HASHMAP_FREE_FUNC f;
} MetadataMap;

/* an internal map to hold metadata for each map object the user creates */
static MetadataMap *INTERNAL_MAP[TOTAL_INTERNAL_BUCKET_SIZE] = {0};

/* creates a new hash map; accepts an integer representing
   total bucket size, and a deallocation function */
map_t hm_new(int n, HASHMAP_FREE_FUNC f) {
	MetadataMap *m = (MetadataMap *)malloc(sizeof(MetadataMap));
	int bucket; 
	int m_idx = 0;

	m->max_bucket_size = n;
	m->f = f;
	m->map = (map_t)malloc(sizeof(void *) * m->max_bucket_size);
	m->key = *(unsigned long *)&m->map;

	bucket = m->key % TOTAL_INTERNAL_BUCKET_SIZE;

	INTERNAL_MAP[bucket] = m;

	/* initialize all map buckets to null */
	for(; m_idx < m->max_bucket_size; ++m_idx) 
		m->map[m_idx] = NULL;

	return m->map;
}

/* set a value in the hash map corresponding to a given key */
int hm_set(map_t m, char *s, void *p) {
	int success = 0;
	int bucket = *(unsigned long *)&m % TOTAL_INTERNAL_BUCKET_SIZE;

	if(INTERNAL_MAP[bucket] == NULL || s == NULL || p == NULL) {
		return success;
	} else {
		MetadataMap *mm = (MetadataMap *)INTERNAL_MAP[bucket];
		unsigned long hash = djb2((unsigned char *)s);
		success = 1;

		bucket = hash % mm->max_bucket_size;

		// todo - implement collision resolution; for that, I'll need to store more info, like the actual key going in.
		// if the key coming in doesn't match the key in the bucket, then I know two or more keys collided, 
		// move to the next bucket until I find the actual key I'm looking for 

		mm->map[bucket] = p;
	}

	return success;
}

/* retrieves the value of a key in the given hash map */
void *hm_get(map_t m, char *s) {
	if(m == NULL) {
		return NULL; 
	} else {
		int bucket = *(unsigned long *)&m % TOTAL_INTERNAL_BUCKET_SIZE;

		if(INTERNAL_MAP[bucket] == NULL || s == NULL) {
			return NULL;
		} else {
			MetadataMap *mm = (MetadataMap *)INTERNAL_MAP[bucket];
			unsigned long hash = djb2((unsigned char *)s);
			bucket = hash % mm->max_bucket_size;

			return mm->map[bucket];
		}
	}
}

/* destroys the hashmap */ 
int hm_destroy(map_t m) {
	int success = 0;

	if(m == NULL) {
		return success;
	} else {
		int bucket = *(unsigned long *)&m % TOTAL_INTERNAL_BUCKET_SIZE;

		if(INTERNAL_MAP[bucket] == NULL) {
			return success;
		} else {
			MetadataMap *mm = (MetadataMap *)INTERNAL_MAP[bucket];
			int m_idx = 0;

			for(; m_idx < mm->max_bucket_size; ++m_idx) {
				if(mm->map[m_idx] != NULL) {
					if(mm->f != NULL) 
						mm->f(mm->map[m_idx]);
					else 
						free(mm->map[m_idx]);
				}
			}
		}
	}

	return success;
}
