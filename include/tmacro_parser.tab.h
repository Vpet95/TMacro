/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TMACRO_PARSER_TAB_H_INCLUDED
# define YY_YY_TMACRO_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    EOL = 258,
    PLACEHOLDER = 259,
    OPEN_TOK = 260,
    CLOSE_TOK = 261,
    WRITE_TOK = 262,
    MOVE_LR_TOK = 263,
    MOVE_UD_TOK = 264,
    INSERT_TOK = 265,
    UPDATE_TOK = 266,
    DELETE_TOK = 267,
    GET_TOK = 268,
    SPLIT_TOK = 269,
    INCR_TOK = 270,
    DECR_TOK = 271,
    IF_TOK = 272,
    ELSE_TOK = 273,
    SWITCH_TOK = 274,
    CASE_TOK = 275,
    DEFAULT_TOK = 276,
    DO_TOK = 277,
    WHILE_TOK = 278,
    TIMES_TOK = 279,
    MATH_OP = 280,
    MOD_TOK = 281,
    ID = 282,
    STR_LIT = 283,
    CHAR_LIT = 284,
    INT_TOK = 285,
    DEC_TOK = 286,
    AND_TOK = 287,
    OR_TOK = 288,
    BOL_TOK = 289,
    EOL_TOK = 290,
    FL_TOK = 291,
    LL_TOK = 292,
    BOF_TOK = 293,
    EOF_TOK = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "tmacro_parser.y" /* yacc.c:1909  */

  char *s; 
  double d;
  long long i;
  char c;

#line 102 "tmacro_parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_TMACRO_PARSER_TAB_H_INCLUDED  */
