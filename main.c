
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/hash_map.h"

typedef struct test {
	int intval;

	char *strval; 
} test; 

void free_test(void *ptr) {
	test *t = (test *)ptr;

	printf("intval: %d, strval: %s\n", t->intval, t->strval);

	if(t->strval != NULL)
		free(t->strval);

	free(ptr);
}

int main(int argc, char **argv) {
	map_t map = hm_new(127, free_test);

	test *t = (test *)malloc(sizeof(test));
	test *t2;
	test *t3 = (test *)malloc(sizeof(test));

	t->intval = 10;
	t->strval = (char *)calloc(20, sizeof(char));
	strcat(t->strval, "Hello, world!");

	char *key = "mydsfkey";
	char *key2 = "testkey2";

	hm_set(map, key, t);

	printf("Before: intval: %d, strval: %s\n", t->intval, t->strval);

	t2 = (test *)hm_get(map, key);

	printf("After: intval: %d, strval: %s\n", t2->intval, t2->strval);

	t3->intval = 42;
	t3->strval = (char *)calloc(20, sizeof(char));
	strcat(t3->strval, "Goodbye bitches");

	hm_set(map, key2, t3);

	hm_destroy(map);

	return 0;
}
