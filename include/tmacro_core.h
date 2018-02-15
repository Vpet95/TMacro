
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

#endif