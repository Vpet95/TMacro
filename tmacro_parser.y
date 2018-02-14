 
%{

#include <string.h>
#include <stdio.h>
#include "tmacro_lexer.lex.c"
#include "include/vector.h"
#include "include/hash_map.h"
#include "include/util.h"
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
%token MATH_OP MOD_TOK
%token ID
%token STR_LIT CHAR_LIT
%token INT_TOK DEC_TOK
%token AND_TOK OR_TOK
%token BOL_TOK EOL_TOK FL_TOK LL_TOK BOF_TOK EOF_TOK

%type<s> PLACEHOLDER
%type<s> open_rule close_rule write_rule lr_rule ud_rule move_rule condition_list
%type<s> insert_rule update_rule delete_rule get_rule mod_rule
%type<s> MATH_OP MOD_TOK
%type<s> INCR_TOK DECR_TOK IF_TOK ELSE_TOK SWITCH_TOK CASE_TOK DEFAULT_TOK
%type<s> DO_TOK WHILE_TOK TIMES_TOK
%type<s> ID
%type<s> STR_LIT CHAR_LIT 
%type<s> DEC_TOK
%type<s> AND_TOK OR_TOK
%type<s> BOL_TOK EOL_TOK FL_TOK LL_TOK BOF_TOK EOF_TOK
%type<s> INSERT_TOK UPDATE_TOK DELETE_TOK GET_TOK SPLIT_TOK

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
  | BOF_TOK { printf("Move to the beginning of file\n"); }
  | EOF_TOK { printf("Move to the end of file\n"); }
  | BOL_TOK { printf("Move to the beginning of line\n"); }
  | EOL_TOK { printf("Move to the end of line\n"); }
  | FL_TOK { printf("Move to the first line\n"); }
  | LL_TOK { printf("Move to the last line\n"); }
  | SPLIT_TOK { printf("Split the current line into two, moving the second half to the next line\n"); }

open_rule: 
  OPEN_TOK '[' STR_LIT ']' {
    /* open a file */
    printf("Open %s\n", $3);
  }

close_rule: 
  CLOSE_TOK {
    /* close the opened file */
    printf("Closing opened file\n");
  }
 
write_rule: 
    WRITE_TOK {
      /* write to the opened file, or error out if none is opened */
      printf("Writing to currently open file\n");
  }
  | WRITE_TOK '[' STR_LIT ']' {
      /* write to the given file, error out if not possible */
      printf("Writing to file %s\n", $3);
  }

move_rule:
    lr_rule { }
  | ud_rule { }

lr_rule:
    MOVE_LR_TOK '[' INT_TOK ']' {
    /* move cursor LEFT or RIGHT INT_TOK spaces */
    printf("Moving cursor %c %lld time(s)\n", $1, $3);
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
      /* move cursor up or down INT_TOK times */
      printf("Moving cursor %c %lld time(s)\n", $1, $3);
    }
  | MOVE_UD_TOK '[' condition_list ']' {
    /* move cursor up or down until condition is met */
    printf("Moving cursor %c until condition is met\n", $1);
  }

condition_list:
  PLACEHOLDER { printf("Found condition list placeholder\n"); }

insert_rule: 
    INSERT_TOK '[' CHAR_LIT ']' {
      printf("Insert singular character %s\n", $3);
  }
  | INSERT_TOK '[' STR_LIT ']' {
      printf("Insert string literal %s\n", $3);
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

mod_rule: 
    MOD_TOK '[' INT_TOK ',' INT_TOK ']' {
      printf("Calling modulus on %lld by %lld\n", $3, $5);
  }
  | MOD_TOK '[' DEC_TOK ',' INT_TOK ']' {
      printf("Calling modulus on %s by %lld\n", $3, $5);
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
    buffer = yy_scan_string(line);
    
    yyparse();
    yy_delete_buffer(buffer);
  }
		
	return 0;
}

void yyerror(const char *s) { 
	printf("Err: syntax error on line %d: [%s]\n",
         get_current_script_line_number(), 
         get_current_script_line_text());

  return;
} 
