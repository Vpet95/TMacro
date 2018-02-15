
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "include/vector.h"
#include "include/util.h"
#include "include/tmacro_core.h"

static char *CURRENT_SCRIPT_LINE_TEXT = "";
static int  CURRENT_SCRIPT_LINE_NUMBER = 0;

static char *loop_content = NULL;

static char *in_file_name;
static FILE *in_file; 
static char *in_file_buffer;
static VECTOR *tokenized_buffer; 

static int in_file_line_count = 0;
static int in_file_row_num = 0;
static int in_file_col_num = 0;

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
		free(loop_content);
	}
}

short open_input_file(char *filename) {
	short success = 0;
	errno = 0;
	char *sub = (char *)malloc(sizeof(char) * strlen(filename) - 1);
	
	strncpy(sub, &filename[1], strlen(filename) - 2);
	
	in_file = fopen(sub, "r");
	
	if(in_file == NULL) {
		printf("ERR: unable to open file %s; errno: %d\n",
				sub, errno);
		exit(errno);
	}
		
	// we won't free sub, we'll keep the file name around 
	in_file_name = sub;
	success = 1;
	
	return success;
}

short close_input_file() {
	int res = 0;
	
	res = fclose(in_file);
	in_file = NULL;
	in_file_name = NULL;
	
	if(in_file_buffer != NULL) {
		free(in_file_buffer);
		in_file_buffer = NULL;
	}
		
	if(tokenized_buffer != NULL) {
		vector_destroy(tokenized_buffer);
		tokenized_buffer = NULL;
		in_file_line_count = 0;
		in_file_row_num = 0;
		in_file_col_num = 0;
	}
	
	return res == 0 ? 1 : res;
}

short read_input_file() {
	short success = 0;
	
	if(in_file == NULL)
		return success;
	
	// get file size 
	fseek(in_file, 0, SEEK_END);
	long fsize = ftell(in_file);
	fseek(in_file, 0, SEEK_SET); // rewind to the beginning of the file 
	
	in_file_buffer = (char *)malloc(sizeof(char) * fsize + 1);
	fread(in_file_buffer, fsize, 1, in_file);
	
	in_file_buffer[fsize] = 0;
	
	success = ferror(in_file) ? 0 : 1;
	
	if(success) {
		tokenized_buffer = tokenize(in_file_buffer, '\n');
		if(tokenized_buffer != NULL)
			in_file_line_count = vector_size(tokenized_buffer);
	}
	
	return success;
}

short is_input_file_open() {
	return in_file == NULL ? 0 : 1;
}

char *get_file_buffer() {
	return in_file_buffer;
}

short write_buffer_to_input_file() {
	short success = 0;
	size_t num_written; 
	
	char *s = join(tokenized_buffer, "\n");
	
	if(in_file == NULL || in_file_name == NULL || s == NULL)
		return success; // never opened, or failed to join buffer 
	
	if(fclose(in_file))
		return success; // failed to close 
	
	errno = 0;
	in_file = fopen(in_file_name, "w");
	
	if(in_file == NULL) {
		printf("Err: unable to open file %s; errno: %d\n", in_file_name, errno);
		exit(errno);
	}
	
	errno = 0;
	num_written = fwrite(s, sizeof(char), strlen(s), in_file);
	
	if(num_written != strlen(s)) {
		printf("ERR: could not write entire buffer to output file.\n%d bytes written of %d; errno: %d\n",
				num_written, strlen(s), errno);
		exit(errno);
	}
	
	success = 1;
	return success;
}

short write_buffer_to_file(char *filename) {
	short success = 0;
	FILE *fp;
	errno = 0;
	size_t num_written; 
	
	char *s = join(tokenized_buffer, "\n");
	
	if(filename == NULL || s == NULL)
		return success;
	
	char *sub = (char *)malloc(sizeof(char) * strlen(filename) - 1);
	strncpy(sub, &filename[1], strlen(filename) - 2);
	
	fp = fopen(sub, "w");
	
	if(fp == NULL) {
		printf("ERR: unable to open file %s; errno: %d\n", sub, errno);
		exit(errno);
	}
	
	errno = 0;
	num_written = fwrite(s, sizeof(char), strlen(s), fp);
	
	if(num_written != strlen(s)) {
		printf("ERR: could not write entire buffer to output file.\n%d bytes written of %d; errno: %d\n",
				num_written, strlen(s), errno);
		exit(errno);
	}
	
	free(sub);
	success = fclose(fp) == 0 ? 1 : 0;
	
	return success;
}

void set_cursor(int col, int row) {
	if(col == INT_MAX) {
		in_file_col_num = strlen((char *)vector_get(tokenized_buffer, in_file_row_num));
	} else {
		in_file_col_num = col;
	}
	
	if(row == INT_MAX) {
		in_file_row_num = in_file_line_count - 1; // first line is 0
	} else {
		in_file_row_num = row;
	}
}

void set_col(int col) {
	if(col == INT_MAX) {
		in_file_col_num = strlen((char *)vector_get(tokenized_buffer, in_file_row_num));
	} else {
		in_file_col_num = col;
	}
}

void set_row(int row) {
	if(row == INT_MAX) {
		in_file_row_num = in_file_line_count - 1; // first line is 0
	} else {
		in_file_row_num = row;
	}
}

void left(int n) {
	if(n > in_file_col_num)
		in_file_col_num = 0;
	else
		in_file_col_num -= n;
}

void right(int n) {
	int line_len = strlen((char *)vector_get(tokenized_buffer, in_file_row_num));
	
	if(in_file_col_num + n > line_len)
		in_file_col_num = line_len;
	else 
		in_file_col_num += n;
}

void up(int n) {
	if(in_file_row_num - n < 0)
		in_file_row_num = 0;
	else 
		in_file_row_num -= n;
}

void down(int n) {
	if(in_file_row_num + n > in_file_line_count - 1)
		in_file_row_num = in_file_line_count - 1;
	else 
		in_file_row_num += n;
}

void insert(char *s) {
	char *line = (char *)vector_get(tokenized_buffer, in_file_row_num);
	char *new_line;
	
	if(in_file_col_num == strlen(line)) {
		int len = strlen(line) + strlen(s) + 1;
		line = (char *)realloc(line, len);
		
		strcat(line, s);
	} else {
		int len = strlen(line) + strlen(s) + 1;
		new_line = (char *)calloc(len, sizeof(char));
		
		strncpy(new_line, line, in_file_col_num + 1);
		strcat(new_line, s);
		strcat(new_line, &line[in_file_col_num + 1]);
		
		vector_remove(tokenized_buffer, in_file_row_num);
		vector_insert(tokenized_buffer, new_line, in_file_row_num);
	}
}
