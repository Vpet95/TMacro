 
%{

#include <string.h>
#include <stdio.h>
#include "tmacro_lexer.lex.c"

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
  ABC { printf("Found ABC\n"); }

 
%%

extern int yyparse();
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

int main(int argc, char **argv) {
	char *input_data = NULL;
  FILE *fp;
  char *infile;

  long fsize = 0;

  if(argc > 1)
    infile = argv[1];

  /* for testing only */
  printf("We are here!\n");
  
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
	
	YY_BUFFER_STATE buffer;
	
	buffer = yy_scan_string(input_data);
	
	yyparse();
	yy_delete_buffer(buffer);
		
	return 0;
}

void yyerror(const char *s) { 
	printf("Err: syntax error on line %d\n", yylineno);

  return;
} 
