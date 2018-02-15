/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "tmacro_parser.y" /* yacc.c:339  */


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


#line 83 "tmacro_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tmacro_parser.tab.h".  */
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
    CONCAT_OP = 281,
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
#line 21 "tmacro_parser.y" /* yacc.c:355  */

  char *s; 
  double d;
  long long i;
  char c;

#line 171 "tmacro_parser.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 202 "tmacro_parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   104,   105,   106,   107,
     108,   109,   110,   113,   121,   133,   136,   141,   142,   145,
     151,   155,   159,   165,   171,   177,   180,   186,   193,   196,
     201,   204,   207,   210,   215,   218,   223,   226,   229,   234,
     237,   240,   243,   246,   249,   252,   255,   260,   277,   278,
     281,   287,   293,   299,   311,   312,   315,   321,   327,   330,
     335,   338,   343,   346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "EOL", "PLACEHOLDER",
  "OPEN_TOK", "CLOSE_TOK", "WRITE_TOK", "MOVE_LR_TOK", "MOVE_UD_TOK",
  "INSERT_TOK", "UPDATE_TOK", "DELETE_TOK", "GET_TOK", "SPLIT_TOK",
  "INCR_TOK", "DECR_TOK", "IF_TOK", "ELSE_TOK", "SWITCH_TOK", "CASE_TOK",
  "DEFAULT_TOK", "DO_TOK", "WHILE_TOK", "TIMES_TOK", "MATH_OP",
  "CONCAT_OP", "ID", "STR_LIT", "CHAR_LIT", "INT_TOK", "DEC_TOK",
  "AND_TOK", "OR_TOK", "BOL_TOK", "EOL_TOK", "FL_TOK", "LL_TOK", "BOF_TOK",
  "EOF_TOK", "'['", "']'", "','", "'='", "$accept", "line", "open_rule",
  "close_rule", "write_rule", "move_rule", "lr_rule", "ud_rule",
  "condition_list", "insert_rule", "update_rule", "delete_rule",
  "get_rule", "var_assignment_rule", "expr", "end_term", "term",
  "concat_rule", "end_concat_term", "concat_term", "incr_rule",
  "decr_rule", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      91,    93,    44,    61
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,   -25,   -48,   -23,   -16,    -2,    13,    33,    34,    35,
     -48,    36,    37,    38,    12,   -48,   -48,   -48,   -48,   -48,
     -48,    49,    64,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,    52,    53,     9,    10,
      -7,    -3,    54,    55,    56,    59,   -48,    14,    58,   -48,
      47,    48,   -48,   -13,     5,    50,    51,     7,    15,    17,
      19,    21,    24,    26,    28,    46,    61,    67,    65,    69,
      70,   -48,    72,   -48,    73,   -48,   -48,   -48,   -48,    66,
     -48,    71,   -48,   -48,   -48,    68,   -48,    74,   -48,    75,
     -48,    76,   -48,    78,   -48,    79,   -48,    80,   -48,    81,
     -11,    23,    60,    62,    77,    82,    83,    84,    85,    86,
      87,    88,   -48,   -48,   -48,   -48,   -48,    72,   -48,   -48,
     -48,   -48,   -48,   -48,    73,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    24,    25,     0,     0,     0,     0,     0,    46,
      22,     0,     0,     0,     0,    18,    19,    20,    21,    16,
      17,     0,     0,     3,     4,     5,     6,    27,    28,     7,
       9,     8,    10,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     1,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    51,    52,    49,    50,
      54,    55,     0,    56,     0,    15,    23,    26,    29,     0,
      30,     0,    33,    34,    37,     0,    36,     0,    41,     0,
      40,     0,    44,     0,    47,     0,    70,     0,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    60,    61,    58,    57,    59,    68,    66,
      67,    69,    64,    63,    65,    31,    32,    39,    38,    43,
      42,    45,    48,    71,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,    63,   -48,
     -48,   -48,   -47,   -48,    16,   -48,    20,     8,   -48,    11,
     -48,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    28,    54,    29,
      30,    31,    32,    33,    71,   116,    72,    73,   123,    74,
      34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    52,    52,    36,   112,    37,    13,   113,
     114,    57,    58,    14,    38,    59,    60,     9,    78,    79,
      15,    16,    17,    18,    19,    20,     9,    21,    39,    53,
      55,    65,    66,    67,    68,    69,    80,    81,    84,    85,
     118,   119,   120,    40,   121,    47,    86,    87,    88,    89,
      90,    91,    92,    93,    49,    94,    95,    96,    97,    98,
      99,   -62,   -68,    41,    42,    43,    44,    45,    46,    48,
      50,    51,    75,    63,    61,    62,    64,   -66,    76,    77,
     -60,    82,    83,   -67,   -61,   102,   -69,   100,   104,   101,
     103,   125,    56,   126,   105,   106,   107,   108,   109,   122,
     110,   111,   124,     0,     0,     0,   115,     0,   127,     0,
     117,     0,     0,   128,   129,   130,   131,   132,   133,   134
};

static const yytype_int8 yycheck[] =
{
      47,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     4,     4,    40,    27,    40,    22,    30,
      31,    28,    29,    27,    40,    28,    29,    13,    41,    42,
      34,    35,    36,    37,    38,    39,    13,    41,    40,    30,
      30,    27,    28,    29,    30,    31,    41,    42,    41,    42,
      27,    28,    29,    40,   101,    43,    41,    42,    41,    42,
      41,    42,    41,    42,     0,    41,    42,    41,    42,    41,
      42,    25,    26,    40,    40,    40,    40,    40,    40,    30,
      28,    28,    24,    27,    30,    30,    27,    26,    41,    41,
      25,    41,    41,    26,    25,    29,    26,    25,    30,    26,
      29,    41,    39,    41,    30,    30,    30,    29,    29,   101,
      30,    30,   101,    -1,    -1,    -1,   100,    -1,    41,    -1,
     100,    -1,    -1,    41,    41,    41,    41,    41,    41,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    22,    27,    34,    35,    36,    37,    38,
      39,    41,    45,    46,    47,    48,    49,    50,    51,    53,
      54,    55,    56,    57,    64,    65,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    43,    30,     0,
      28,    28,     4,    30,    52,    30,    52,    28,    29,    28,
      29,    30,    30,    27,    27,    27,    28,    29,    30,    31,
      56,    58,    60,    61,    63,    24,    41,    41,    41,    42,
      41,    42,    41,    41,    41,    42,    41,    42,    41,    42,
      41,    42,    41,    42,    41,    42,    41,    42,    41,    42,
      25,    26,    29,    29,    30,    30,    30,    30,    29,    29,
      30,    30,    27,    30,    31,    58,    59,    60,    27,    28,
      29,    56,    61,    62,    63,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    51,    51,    52,    53,    53,    53,    53,
      54,    54,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    59,    59,
      60,    60,    60,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     4,     1,     1,     4,
       4,     6,     6,     4,     4,     1,     4,     4,     6,     6,
       4,     4,     6,     6,     4,     6,     1,     4,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       4,     6,     4,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 64 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1469 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1475 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1481 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 67 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1487 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 68 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1493 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1499 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1505 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1511 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 72 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1517 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1523 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 74 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1529 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 75 "tmacro_parser.y" /* yacc.c:1646  */
    { set_print_or_execute(PRINT); }
#line 1535 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 76 "tmacro_parser.y" /* yacc.c:1646  */
    { 
      VECTOR *lines;
      int n_lines;
      int loop_idx = 0;
      int line_idx = 0;
      char *lc;

      lc = get_loop_content();

      set_print_or_execute(EXECUTE);

      lines = tokenize(lc, '\n');
      n_lines = vector_size(lines);

      for(; loop_idx < (yyvsp[-1].i); ++loop_idx) {
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
#line 1568 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "tmacro_parser.y" /* yacc.c:1646  */
    { set_cursor(0, 0); }
#line 1574 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "tmacro_parser.y" /* yacc.c:1646  */
    { set_cursor(INT_MAX, INT_MAX); }
#line 1580 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 106 "tmacro_parser.y" /* yacc.c:1646  */
    { set_col(0); }
#line 1586 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "tmacro_parser.y" /* yacc.c:1646  */
    { set_col(INT_MAX); }
#line 1592 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "tmacro_parser.y" /* yacc.c:1646  */
    { set_row(0); }
#line 1598 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 109 "tmacro_parser.y" /* yacc.c:1646  */
    { set_row(INT_MAX); }
#line 1604 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "tmacro_parser.y" /* yacc.c:1646  */
    { printf("Split the current line into two, moving the second half to the next line\n"); }
#line 1610 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "tmacro_parser.y" /* yacc.c:1646  */
    {
	short success = open_input_file((yyvsp[-1].s));
	
	if(success) 
	  read_input_file();
  }
#line 1621 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "tmacro_parser.y" /* yacc.c:1646  */
    {
	short success = close_input_file();
	
	if(!success) {
	  if(!is_input_file_open())
	    printf("ERR: unable to close file; no input file open\n");
	  else 
	    printf("ERR: unable to close file; unknown error has occurred\n");
	}
  }
#line 1636 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 133 "tmacro_parser.y" /* yacc.c:1646  */
    {
      write_buffer_to_input_file();
  }
#line 1644 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 136 "tmacro_parser.y" /* yacc.c:1646  */
    {
      write_buffer_to_file((yyvsp[-1].s));
  }
#line 1652 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 141 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1658 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 142 "tmacro_parser.y" /* yacc.c:1646  */
    { }
#line 1664 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "tmacro_parser.y" /* yacc.c:1646  */
    {
      if((yyvsp[-3].c) == 'l' || (yyvsp[-3].c) == 'L')
	    left((yyvsp[-1].i));
	  else if((yyvsp[-3].c) == 'r' || (yyvsp[-3].c) == 'R')
	    right((yyvsp[-1].i));
  }
#line 1675 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 151 "tmacro_parser.y" /* yacc.c:1646  */
    {
    /* move cursor until condition is met */
    printf("Moving cursor %c until condition is met\n", (yyvsp[-3].c));
  }
#line 1684 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 155 "tmacro_parser.y" /* yacc.c:1646  */
    {
    /* move cursor left or right INT_TOK tokens delimited by CHAR_LIT */
    printf("Moving cursor %c %lld token(s) delimited by %s\n", (yyvsp[-5].c), (yyvsp[-3].i), (yyvsp[-1].s));
  }
#line 1693 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 159 "tmacro_parser.y" /* yacc.c:1646  */
    {
    /* move cursor left or right by token (delimited by CHAR_LIT) until condition is met */
    printf("Moving cursor %c by token (delimited by %s) until condition is met\n", (yyvsp[-5].c), (yyvsp[-1].s));
  }
#line 1702 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 165 "tmacro_parser.y" /* yacc.c:1646  */
    {
      if((yyvsp[-3].c) == 'u' || (yyvsp[-3].c) == 'U')
	    up((yyvsp[-1].i));
	  else if((yyvsp[-3].c) == 'd' || (yyvsp[-3].c) == 'D')
	    down((yyvsp[-1].i));
    }
#line 1713 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 171 "tmacro_parser.y" /* yacc.c:1646  */
    {
    /* move cursor up or down until condition is met */
    printf("Moving cursor %c until condition is met\n", (yyvsp[-3].c));
  }
#line 1722 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 177 "tmacro_parser.y" /* yacc.c:1646  */
    { printf("Found condition list placeholder\n"); }
#line 1728 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 180 "tmacro_parser.y" /* yacc.c:1646  */
    {
	  char in[2] = {0};
	  in[0] = (yyvsp[-1].s)[1];
	  
      insert(in);
  }
#line 1739 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 186 "tmacro_parser.y" /* yacc.c:1646  */
    {
      char *sub = (char *)malloc(sizeof(char) * strlen((yyvsp[-1].s)) - 1);
	  strncpy(sub, &(yyvsp[-1].s)[1], strlen((yyvsp[-1].s)) - 2);
	  
	  insert(sub);
	  free(sub);
  }
#line 1751 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Insert character %s %lld times\n", (yyvsp[-3].s), (yyvsp[-1].i));
  }
#line 1759 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Insert string %s %lld times\n", (yyvsp[-3].s), (yyvsp[-1].i));
  }
#line 1767 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 201 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Update singular character %s\n", (yyvsp[-1].s));
  }
#line 1775 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 204 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Update string literal %s\n", (yyvsp[-1].s));
  }
#line 1783 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 207 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Update character %s %lld times\n", (yyvsp[-3].s), (yyvsp[-1].i));
  }
#line 1791 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 210 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Update string %s %lld times\n", (yyvsp[-3].s), (yyvsp[-1].i));
  }
#line 1799 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 215 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Delete %lld character(s)\n", (yyvsp[-1].i));
  }
#line 1807 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 218 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Delete %lld token(s) delimited by %s\n", (yyvsp[-3].i), (yyvsp[-1].s));
  }
#line 1815 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 223 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Return a single character\n");
  }
#line 1823 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 226 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Return %lld character(s)\n", (yyvsp[-1].i));
  }
#line 1831 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 229 "tmacro_parser.y" /* yacc.c:1646  */
    {
      printf("Return %lld token(s) delimited by %s\n", (yyvsp[-3].i), (yyvsp[-1].s));
  }
#line 1839 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 234 "tmacro_parser.y" /* yacc.c:1646  */
    {
      /* assignment to a literal */
  }
#line 1847 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 237 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 1855 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 240 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 1863 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 243 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 1871 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 246 "tmacro_parser.y" /* yacc.c:1646  */
    {
      /* assignment to the value of another variable */
  }
#line 1879 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 249 "tmacro_parser.y" /* yacc.c:1646  */
    {
      /* assignment to a value from the text buffer */
  }
#line 1887 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "tmacro_parser.y" /* yacc.c:1646  */
    {
      /* eval expression, assign it here */
  }
#line 1895 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 255 "tmacro_parser.y" /* yacc.c:1646  */
    {
      /* set the variable to the concatenated string */
  }
#line 1903 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 260 "tmacro_parser.y" /* yacc.c:1646  */
    {
      char *c = (char *)calloc(strlen((yyvsp[-2].s)) + 1 + strlen((yyvsp[0].s)) + 4, sizeof(char));

      strcat(c, (yyvsp[-2].s));
      strcat(c, " ");
      strcat(c, (yyvsp[-1].s));
      strcat(c, " ");
      strcat(c, (yyvsp[0].s));
      strcat(c, " ");

      free((yyvsp[-2].s));
      free((yyvsp[0].s));

      (yyval.s) = c;
  }
#line 1923 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 277 "tmacro_parser.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s); }
#line 1929 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 278 "tmacro_parser.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s); }
#line 1935 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 281 "tmacro_parser.y" /* yacc.c:1646  */
    { 
      char *c = (char *)calloc(15, sizeof(char));
      sprintf(c, "%lld", (yyvsp[0].i));

      (yyval.s) = c;
  }
#line 1946 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 287 "tmacro_parser.y" /* yacc.c:1646  */
    {
      char *c = (char *)calloc(15, sizeof(char));
      strcpy(c, (yyvsp[0].s));

      (yyval.s) = c;
  }
#line 1957 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 293 "tmacro_parser.y" /* yacc.c:1646  */
    {
    
    // grab value of variable, convert to string, return 
  }
#line 1966 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 299 "tmacro_parser.y" /* yacc.c:1646  */
    {
      char *c = (char *)calloc(strlen((yyvsp[-2].s)) + 2 + strlen((yyvsp[0].s)), sizeof(char));
      strcat(c, (yyvsp[-2].s));
      strcat(c, (yyvsp[0].s));

      free((yyvsp[-2].s));
      free((yyvsp[0].s));

      (yyval.s) = c;
  }
#line 1981 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 311 "tmacro_parser.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s); }
#line 1987 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 312 "tmacro_parser.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s); }
#line 1993 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 315 "tmacro_parser.y" /* yacc.c:1646  */
    { 
      char *c = (char *)calloc(strlen((yyvsp[0].s)) - 1, sizeof(char));
      strncpy(c, &(yyvsp[0].s)[1], strlen((yyvsp[0].s)) - 2);

      (yyval.s) = c;
  }
#line 2004 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 321 "tmacro_parser.y" /* yacc.c:1646  */
    { 
      char *c = (char *)calloc(2, sizeof(char));
      c[0] = (yyvsp[0].s)[1];

      (yyval.s) = c;
  }
#line 2015 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 327 "tmacro_parser.y" /* yacc.c:1646  */
    {
    // grab value of variable, convert to string, return
  }
#line 2023 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 330 "tmacro_parser.y" /* yacc.c:1646  */
    {
    // grab data from the text buffer, and concatenate it in 
  }
#line 2031 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 335 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 2039 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 338 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 2047 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 343 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 2055 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 346 "tmacro_parser.y" /* yacc.c:1646  */
    {

  }
#line 2063 "tmacro_parser.tab.c" /* yacc.c:1646  */
    break;


#line 2067 "tmacro_parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 350 "tmacro_parser.y" /* yacc.c:1906  */


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
