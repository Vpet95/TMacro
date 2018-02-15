
#ifndef TMACRO_CORE_DEF

#define TMACRO_CORE_DEF

/* returns the text of the current line in 
   the TMacro script file for error reporting */
char *get_current_script_line_text();

/* sets a pointer to the current line in the 
   TMacro script file for error reporting */
void set_current_script_line_text(char *);

/* returns the line number of the current line in the 
   TMacro script file for error reporting. */
int get_current_script_line_number();

/* sets the line number of the current line in the 
   TMacro script file for error reporting */
void set_current_script_line_number(int);

void add_loop_content(char *);

char *get_loop_content();

void clear_loop_content();

short open_input_file(char *);

short close_input_file();

short read_input_file();

short is_input_file_open();

// for debugging only, shouldn't be used for program execution
char *get_file_buffer();

short write_buffer_to_input_file();

short write_buffer_to_file(char *);

void set_cursor(int, int);

void set_col(int);

void set_row(int);

void left(int);

void right(int);

void up(int);

void down(int);

void insert(char *);

#endif