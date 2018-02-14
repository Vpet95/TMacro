
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/vector.h"
#include "include/util.h"

#define TRUE 1
#define FALSE 0

VECTOR *tokenize(char *s, char c) {
	VECTOR *ret = vector_create(1, 2, NULL, free);

	int in_token = FALSE;

	/* initialize our looping variables */
	unsigned int c_i = 0;
	int s_len = strlen(s);

	/* initialize our token boundary variables */
	unsigned int tok_start = c_i;
	unsigned int tok_end = c_i;

	for(; c_i < s_len; ++c_i) {
		if(s[c_i] == c) {
			if(in_token) {
				/* we were just in a token, and we found our delimeter character, 
				   grab the token and throw it in the vector */
				unsigned int tok_len = tok_end - tok_start + 1;
				char *token = (char *)calloc(tok_len + 1, sizeof(char)); 

				strncpy(token, &s[tok_start], tok_len);

				vector_push_back(ret, token);

				in_token = FALSE;
			}  else { 
				/* we weren't in our token, there must me 
				multiple delimiters grouped together */
			}
		} else {
			if(in_token) {
				/* we are already in a token, nothing special to do here other than
				   increment the tok_end */
				++tok_end;
			} else {
				/* we just finished looking at a delimeter, or the loop just started,
				   either way the current character denotes the start of a new token */
				tok_start = c_i;
				tok_end = tok_start;

				in_token = TRUE;
			}
		}
	}

	/* the string might end on a valid token, we want to grab it */
	if(in_token) {
		unsigned int tok_len = tok_end - tok_start + 1;
		char *token = (char *)calloc(tok_len + 1, sizeof(char)); 

		strncpy(token, &s[tok_start], tok_len);

		vector_push_back(ret, token);
	}

	return ret; 
}

/* Dan Bernstein's djb2 hash algorithm */
unsigned long djb2(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}


