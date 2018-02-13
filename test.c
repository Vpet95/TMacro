
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "include/vector.h"
#include "include/util.h"

/*
	This file serves as a test playground to validate different pieces of functionality work as intended. 
*/

int main(int argc, char *argv[]) {
	VECTOR *v = vector_create(1, 1, NULL, free);

	char *c1 = "Hello";
	char *c2 = "Goodbye";

	vector_push_copy(v, c1, sizeof(c1));
	vector_push_copy(v, c2, sizeof(c2));

	printf("String 1: %s\n", (char *)vector_get(v, 0));
	printf("String 2: %s\n", (char *)vector_get(v, 1));

	return 0;
}