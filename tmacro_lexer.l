
%{

#include <string.h>
#include "include/tmacro_parser.tab.h"

/* this defines the End of File token and behavior; without it, 
 * bison rules which rely on EOF can't work */
#define yyterminate() return END

%}

%option stack
%option noyywrap 
%option yylineno 

/* define states here */


/* regex section */

%%

"abc" { return ABC; }

. { /* do nothing */ }

%%

#pragma warn