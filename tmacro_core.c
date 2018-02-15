
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/vector.h"
#include "include/util.h"
#include "include/tmacro_core.h"

static char *CURRENT_SCRIPT_LINE_TEXT = "";
static int  CURRENT_SCRIPT_LINE_NUMBER = 0;

static char *loop_content = NULL;

char *get_current_script_line_text() {
	return CURRENT_SCRIPT_LINE_TEXT;
}

void set_current_script_line_text(char *l) {
	CURRENT_SCRIPT_LINE_TEXT = l;
}

int get_current_script_line_number() {
	return CURRENT_SCRIPT_LINE_NUMBER;
}

void set_current_script_line_number(int n) {
	CURRENT_SCRIPT_LINE_NUMBER = n;
}

void add_loop_content(char *str) {
	if(loop_content == NULL)
		loop_content = (char *)calloc(strlen(str) + 1, sizeof(char));
	else 
		loop_content = (char *)realloc(loop_content, strlen(loop_content) + strlen(str) + 1);

	strcat(loop_content, str);
}

char *get_loop_content() {
	return loop_content;
}

void clear_loop_content() {
	if(loop_content != NULL) {
		printf("Here");
		free(loop_content);
	}
}