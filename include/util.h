
#ifndef UTIL_H_DEF

#define UTIL_H_DEF

#include "vector.h"

typedef enum execution_type {
	EXECUTE,
	PRINT
} execution_type;

/* accepts a source string, and a character delimiter, and returns a tokenized 
   vector of strings */
VECTOR *tokenize(char *, char);

/* the reverse of tokenize */
char *join(VECTOR *, char *);

/* Dan Bernstein's djb2 hash algorithm */
unsigned long djb2(unsigned char *);

void set_print_or_execute(execution_type);

execution_type get_print_or_execute();




#endif 