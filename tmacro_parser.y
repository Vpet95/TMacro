 
%{

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "tmacro_lexer.lex.c"
#include "include/vector.h"
#include "include/hash_map.h"
#include "include/util.h"
#include "include/tinyexpr.h"
#include "include/tmacro_core.h"

int yylex();
void yyerror(const char *s);

%}

%locations

%union {
  char *s; 
  double d;
  long long i;
  char c;
}

%token EOL END 0 "end of file"

%token PLACEHOLDER
%token OPEN_TOK CLOSE_TOK WRITE_TOK MOVE_LR_TOK MOVE_UD_TOK
%token INSERT_TOK UPDATE_TOK DELETE_TOK GET_TOK SPLIT_TOK
%token INCR_TOK DECR_TOK IF_TOK ELSE_TOK SWITCH_TOK CASE_TOK DEFAULT_TOK
%token DO_TOK WHILE_TOK TIMES_TOK
%token MATH_OP CONCAT_OP
%token ID
%token STR_LIT CHAR_LIT
%token INT_TOK DEC_TOK
%token AND_TOK OR_TOK
%token BOL_TOK EOL_TOK FL_TOK LL_TOK BOF_TOK EOF_TOK

%type<s> PLACEHOLDER
%type<s> open_rule close_rule write_rule lr_rule ud_rule move_rule condition_list
%type<s> insert_rule update_rule delete_rule get_rule
%type<s> var_assignment_rule incr_rule decr_rule 
%type<s> MATH_OP CONCAT_OP
%type<s> INCR_TOK DECR_TOK IF_TOK ELSE_TOK SWITCH_TOK CASE_TOK DEFAULT_TOK
%type<s> DO_TOK WHILE_TOK TIMES_TOK
%type<s> ID
%type<s> STR_LIT CHAR_LIT 
%type<s> DEC_TOK
%type<s> AND_TOK OR_TOK
%type<s> BOL_TOK EOL_TOK FL_TOK LL_TOK BOF_TOK EOF_TOK
%type<s> INSERT_TOK UPDATE_TOK DELETE_TOK GET_TOK SPLIT_TOK
%type<s> term expr end_term concat_rule concat_term end_concat_term

%type<c> MOVE_LR_TOK MOVE_UD_TOK

%type<i> INT_TOK

%%

line: /* empty line */
  | open_rule { }
  | close_rule { }
  | write_rule { }
  | move_rule { }
  | insert_rule { }
  | delete_rule { }
  | update_rule { }
  | get_rule { }
  | var_assignment_rule { }
  | incr_rule { }
  | decr_rule { }
  | DO_TOK '[' { set_print_or_execute(PRINT); }
  | ']' INT_TOK TIMES_TOK { 
      VECTOR *lines;
      int n_lines;
      int loop_idx = 0;
      int line_idx = 0;
      char *lc;

      lc = get_loop_content();

      set_print_or_execute(EXECUTE);

      lines = tokenize(lc, '\n');
      n_lines = vector_size(lines);

      for(; loop_idx < $2; ++loop_idx) {
        line_idx = 0;
        for(; line_idx < n_lines; ++line_idx) {
          YY_BUFFER_STATE buffer2;
          char *line = vector_get(lines, line_idx);

          buffer2 = yy_scan_string(line);
          yyparse();

          if(line_idx < n_lines - 1)
            yy_delete_buffer(buffer2);
        }
      }
  }
  | BOF_TOK { set_cursor(0, 0); }
  | EOF_TOK { set_cursor(INT_MAX, INT_MAX); }
  | BOL_TOK { set_col(0); }
  | EOL_TOK { set_col(INT_MAX); }
  | FL_TOK { set_row(0); }
  | LL_TOK { set_row(INT_MAX); }
  | SPLIT_TOK { printf("Split the current line into two, moving the second half to the next line\n"); }

open_rule: 
  OPEN_TOK '[' STR_LIT ']' {
	short success = open_input_file($3);
	
	if(success) 
	  read_input_file();
  }

close_rule: 
  CLOSE_TOK {
	short success = close_input_file();
	
	if(!success) {
	  if(!is_input_file_open())
	    printf("ERR: unable to close file; no input file open\n");
	  else 
	    printf("ERR: unable to close file; unknown error has occurred\n");
	}
  }
 
write_rule: 
    WRITE_TOK {
      write_buffer_to_input_file();
  }
  | WRITE_TOK '[' STR_LIT ']' {
      write_buffer_to_file($3);
  }

move_rule:
    lr_rule { }
  | ud_rule { }

lr_rule:
    MOVE_LR_TOK '[' INT_TOK ']' {
      if($1 == 'l' || $1 == 'L')
	    left($3);
	  else if($1 == 'r' || $1 == 'R')
	    right($3);
  }
  | MOVE_LR_TOK '[' condition_list ']' {
    /* move cursor until condition is met */
    printf("Moving cursor %c until condition is met\n", $1);
  }
  | MOVE_LR_TOK '[' INT_TOK ',' CHAR_LIT ']' {
    /* move cursor left or right INT_TOK tokens delimited by CHAR_LIT */
    printf("Moving cursor %c %lld token(s) delimited by %s\n", $1, $3, $5);
  }
  | MOVE_LR_TOK '[' condition_list ',' CHAR_LIT ']' {
    /* move cursor left or right by token (delimited by CHAR_LIT) until condition is met */
    printf("Moving cursor %c by token (delimited by %s) until condition is met\n", $1, $5);
  } 

ud_rule:
    MOVE_UD_TOK '[' INT_TOK ']' {
      if($1 == 'u' || $1 == 'U')
	    up($3);
	  else if($1 == 'd' || $1 == 'D')
	    down($3);
    }
  | MOVE_UD_TOK '[' condition_list ']' {
    /* move cursor up or down until condition is met */
    printf("Moving cursor %c until condition is met\n", $1);
  }

condition_list:
  PLACEHOLDER { printf("Found condition list placeholder\n"); }

insert_rule: 
    INSERT_TOK '[' CHAR_LIT ']' {
	  char in[2] = {0};
	  in[0] = $3[1];
	  
      insert(in);
  }
  | INSERT_TOK '[' STR_LIT ']' {
      char *sub = (char *)malloc(sizeof(char) * strlen($3) - 1);
	  strncpy(sub, &$3[1], strlen($3) - 2);
	  
	  insert(sub);
	  free(sub);
  }
  | INSERT_TOK '[' CHAR_LIT ',' INT_TOK ']' {
      printf("Insert character %s %lld times\n", $3, $5);
  }
  | INSERT_TOK '[' STR_LIT ',' INT_TOK ']' {
      printf("Insert string %s %lld times\n", $3, $5);
  }

update_rule: 
    UPDATE_TOK '[' CHAR_LIT ']' {
      printf("Update singular character %s\n", $3);
  }
  | UPDATE_TOK '[' STR_LIT ']' {
      printf("Update string literal %s\n", $3);
  }
  | UPDATE_TOK '[' CHAR_LIT ',' INT_TOK ']' {
      printf("Update character %s %lld times\n", $3, $5);
  }
  | UPDATE_TOK '[' STR_LIT ',' INT_TOK ']' {
      printf("Update string %s %lld times\n", $3, $5);
  }

delete_rule: 
    DELETE_TOK '[' INT_TOK ']' {
      printf("Delete %lld character(s)\n", $3);
  } 
  | DELETE_TOK '[' INT_TOK ',' CHAR_LIT ']' {
      printf("Delete %lld token(s) delimited by %s\n", $3, $5);
  }

get_rule: 
    GET_TOK {
      printf("Return a single character\n");
  }
  | GET_TOK '[' INT_TOK ']' {
      printf("Return %lld character(s)\n", $3);
  }
  | GET_TOK '[' INT_TOK ',' CHAR_LIT ']' {
      printf("Return %lld token(s) delimited by %s\n", $3, $5);
  }

var_assignment_rule: 
    ID '=' INT_TOK {
      /* assignment to a literal */
  }
  | ID '=' DEC_TOK {

  }
  | ID '=' STR_LIT {

  }
  | ID '=' CHAR_LIT {

  }
  | ID '=' ID {
      /* assignment to the value of another variable */
  }
  | ID '=' get_rule {
      /* assignment to a value from the text buffer */
  } 
  | ID '=' expr {
      /* eval expression, assign it here */
  }
  | ID '=' concat_rule {
      /* set the variable to the concatenated string */
  }

expr: 
  term MATH_OP end_term {
      char *c = (char *)calloc(strlen($1) + 1 + strlen($3) + 4, sizeof(char));

      strcat(c, $1);
      strcat(c, " ");
      strcat(c, $2);
      strcat(c, " ");
      strcat(c, $3);
      strcat(c, " ");

      free($1);
      free($3);

      $$ = c;
  }

end_term: 
    expr { $$ = $1; }
  | term { $$ = $1; }

term: 
    INT_TOK { 
      char *c = (char *)calloc(15, sizeof(char));
      sprintf(c, "%lld", $1);

      $$ = c;
  }
  | DEC_TOK {
      char *c = (char *)calloc(15, sizeof(char));
      strcpy(c, $1);

      $$ = c;
  }
  | ID {
    
    // grab value of variable, convert to string, return 
  }

concat_rule: 
  concat_term CONCAT_OP end_concat_term {
      char *c = (char *)calloc(strlen($1) + 2 + strlen($3), sizeof(char));
      strcat(c, $1);
      strcat(c, $3);

      free($1);
      free($3);

      $$ = c;
  }

end_concat_term: 
    concat_rule { $$ = $1; }
  | concat_term { $$ = $1; }

concat_term: 
    STR_LIT { 
      char *c = (char *)calloc(strlen($1) - 1, sizeof(char));
      strncpy(c, &$1[1], strlen($1) - 2);

      $$ = c;
  }
  | CHAR_LIT { 
      char *c = (char *)calloc(2, sizeof(char));
      c[0] = $1[1];

      $$ = c;
  }
  | ID {
    // grab value of variable, convert to string, return
  }
  | get_rule {
    // grab data from the text buffer, and concatenate it in 
  }

incr_rule: 
    INCR_TOK '[' ID ']' {

  }
  | INCR_TOK '[' ID ',' INT_TOK ']' {

  }

decr_rule: 
    DECR_TOK '[' ID ']' {

  }
  | DECR_TOK '[' ID ',' INT_TOK ']' {

  }

%%

extern int yyparse();
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

int main(int argc, char **argv) {
	char *input_data = NULL;
  FILE *fp;
  char *infile;

  long fsize = 0;

  VECTOR *lines; 
  unsigned int n_lines;
  unsigned int l_idx = 0;

  if(argc > 1)
    infile = argv[1];
  else {
    printf("TMacro Err: missing input file; stopping.\n");
    exit(1);
  }
  
  fp = fopen(infile, "r");
  if(fp) {
    fseek(fp, 0L, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);
    
    input_data = (char *)malloc((fsize + 1) * sizeof(char));
    fread(input_data, fsize, 1, fp);
    
    input_data[fsize] = 0;
    fclose(fp);
  } else {
    printf("Unable to open file %s\n", infile);
  }

  /* for testing purposes */
  lines = tokenize(input_data, '\n');
  n_lines = vector_size(lines);
	
  for(; l_idx < n_lines; ++l_idx) {
    YY_BUFFER_STATE buffer;
    char *line = vector_get(lines, l_idx);

    set_current_script_line_text(line);
    set_current_script_line_number(l_idx + 1);

    if(get_print_or_execute() == PRINT && line[0] != ']') {
      add_loop_content(line);
      add_loop_content("\n");
    } else {
      buffer = yy_scan_string(line);
    
      yyparse();
      yy_delete_buffer(buffer);
    } 
  }
		
	return 0;
}

void yyerror(const char *s) { 
	printf("Err: syntax error on line %d: [%s]\n",
         get_current_script_line_number(), 
         get_current_script_line_text());

  return;
} 
