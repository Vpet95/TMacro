 
%{

#include <string.h>
#include <stdio.h>
#include "tmacro_lexer.lex.c"
#include "include/vector.h"
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
  
}

%token EOL END 0 "end of file"

%token ABC

%type<s> ABC

%%

line: 
  ABC {
    printf("Found abc\n");
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
