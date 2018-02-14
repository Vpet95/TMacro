
#ifndef UTIL_H_DEF

#define UTIL_H_DEF

#include "vector.h"

/* accepts a source string, and a character delimiter, and returns a tokenized 
   vector of strings */
VECTOR *tokenize(char *, char);

/* Dan Bernstein's djb2 hash algorithm */
unsigned long djb2(unsigned char *);


#endif 