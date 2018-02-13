
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/vector.h"
#include "include/util.h"
#include "include/tmacro_core.h"

static char *CURRENT_SCRIPT_LINE_TEXT = "";
static int  CURRENT_SCRIPT_LINE_NUMBER = 0;

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