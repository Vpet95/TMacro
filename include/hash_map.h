
#ifndef HASH_MAP_DEF

#define HASH_MAP_DEF

/* our hash map will be an array of void pointers; the 
   caller can decide what they want to store */
typedef void** map_t;

/** Typedef for a function to free a pointer. 
*/
typedef void (*HASHMAP_FREE_FUNC)(void *ptr);

/* creates a new hash map; accepts an integer representing
   total bucket size as an argument */
map_t hm_new(int, HASHMAP_FREE_FUNC);

/* set a value in the hash map corresponding to a given key */
int hm_set(map_t, char *, void *);

/* retrieves the value of a key in the given hash map */
void *hm_get(map_t, char *);

/* destroys the hashmap */ 
int hm_destroy(map_t);

#endif