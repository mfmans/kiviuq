/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"


/*
	$ [KiPHP] /r5/syntax/parser.y  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#define KI_SYNTAX_DEFINITION


#include "../../kiviuq.h"
#include "../syntax.h"
#include "../syntax_parser.h"





/* Line 189 of yacc.c  */
#line 93 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.yy.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 0,
     T_UNDEFINED = 258,
     T_LOGICAL_OR = 259,
     T_LOGICAL_XOR = 260,
     T_LOGICAL_AND = 261,
     T_EQUAL_ARROW = 262,
     T_EQUAL_SHR = 263,
     T_EQUAL_SHL = 264,
     T_EQUAL_XOR = 265,
     T_EQUAL_OR = 266,
     T_EQUAL_AND = 267,
     T_EQUAL_MOD = 268,
     T_EQUAL_CAT = 269,
     T_EQUAL_DIV = 270,
     T_EQUAL_MUL = 271,
     T_EQUAL_SUB = 272,
     T_EQUAL_ADD = 273,
     T_BOOLEAN_OR = 274,
     T_BOOLEAN_AND = 275,
     T_IS_SMALLER_GREATER = 276,
     T_IS_NOT_IDENTICAL = 277,
     T_IS_IDENTICAL = 278,
     T_IS_NOT_EQUAL = 279,
     T_IS_EQUAL = 280,
     T_IS_GREATER_EQUAL = 281,
     T_IS_SMALLER_EQUAL = 282,
     T_SHR = 283,
     T_SHL = 284,
     T_INSTANCEOF = 285,
     T_CAST_BOOLEAN = 286,
     T_CAST_OBJECT = 287,
     T_CAST_ARRAY = 288,
     T_CAST_STRING = 289,
     T_CAST_FLOAT = 290,
     T_CAST_INTEGER = 291,
     T_DEC = 292,
     T_INC = 293,
     T_NEW = 294,
     T_CLONE = 295,
     T_CHILD = 296,
     T_COLON = 297,
     T_CLASS = 298,
     T_INTERFACE = 299,
     T_EXTENDS = 300,
     T_IMPLEMENTS = 301,
     T_PUBLIC = 302,
     T_PROTECTED = 303,
     T_PRIVATE = 304,
     T_FINAL = 305,
     T_ABSTRACT = 306,
     T_STATIC = 307,
     T_CONST = 308,
     T_FUNCTION = 309,
     T_GLOBAL = 310,
     T_RETURN = 311,
     T_IF = 312,
     T_ELSEIF = 313,
     T_ELSE = 314,
     T_WHILE = 315,
     T_DO = 316,
     T_FOR = 317,
     T_FOREACH = 318,
     T_AS = 319,
     T_SWITCH = 320,
     T_CASE = 321,
     T_DEFAULT = 322,
     T_CONTINUE = 323,
     T_BREAK = 324,
     T_TRY = 325,
     T_CATCH = 326,
     T_FINALLY = 327,
     T_THROW = 328,
     T_INCLUDE = 329,
     T_INCLUDE_ONCE = 330,
     T_REQUIRE = 331,
     T_REQUIRE_ONCE = 332,
     T_ECHO = 333,
     T_EXIT = 334,
     T_EVAL = 335,
     T_ISSET = 336,
     T_UNSET = 337,
     T_EMPTY = 338,
     T_ARRAY = 339,
     T_LIST = 340,
     T_CONSTANT_TRUE = 341,
     T_CONSTANT_FALSE = 342,
     T_CONSTANT_NULL = 343,
     T_CONSTANT_FUNCTION = 344,
     T_CONSTANT_CLASS = 345,
     T_CONSTANT_METHOD = 346,
     T_CONSTANT_DIR = 347,
     T_CONSTANT_FILE = 348,
     T_HTML = 349,
     T_INTEGER = 350,
     T_FLOAT = 351,
     T_STRING = 352,
     T_ENCODE_INTEGER = 353,
     T_ENCODE_STRING = 354,
     T_VARIABLE = 355,
     T_IDENTIFIER = 356,
     T_PRAGMA_EXPORT = 357,
     T_PRAGMA_ENCODE = 358,
     T_PRAGMA_INLINE = 359,
     T_PRAGMA_VM_WRAPPER = 360,
     T_PRAGMA_VM_ENTRY = 361,
     T_PRAGMA_VM_HEAP = 362,
     T_PRAGMA_VM_STACK = 363,
     T_PRAGMA_VM_TOP = 364,
     T_PRAGMA_VM_BOTTOM = 365,
     T_PRAGMA_VM_EXCEPTION = 366,
     T_PRAGMA_VM_PROGRAM = 367,
     T_PRAGMA_VM_RETURN = 368,
     T_PRAGMA_VM_MIDDLE = 369
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 250 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.yy.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   616

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  140
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNRULES -- Number of states.  */
#define YYNSTATES  274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   369

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,    44,    27,     2,
     134,   135,    42,    39,     4,    40,    41,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,   138,
      33,     8,    34,    21,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,   139,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,    25,   137,    47,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    23,    24,    28,    29,    30,    31,
      32,    35,    36,    37,    38,    46,    49,    50,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      22,    27,    32,    37,    42,    47,    52,    57,    62,    67,
      72,    77,    82,    87,    92,    97,   100,   101,   108,   109,
     111,   113,   117,   121,   123,   125,   129,   131,   135,   139,
     141,   142,   152,   153,   155,   157,   158,   161,   162,   165,
     169,   171,   172,   175,   179,   183,   186,   187,   190,   192,
     194,   196,   198,   200,   202,   206,   208,   212,   216,   218,
     220,   224,   225,   228,   232,   235,   237,   241,   245,   251,
     254,   259,   263,   267,   271,   277,   281,   283,   284,   287,
     291,   295,   297,   299,   303,   307,   309,   313,   315,   317,
     318,   325,   326,   331,   332,   334,   335,   340,   342,   346,
     347,   351,   353,   355,   357,   358,   361,   366,   371,   378,
     385,   387,   389,   390,   396,   397,   399,   402,   406,   408,
     410,   414,   416,   418,   419,   425,   426,   428,   431,   435,
     437,   439,   443,   445,   447,   449,   451,   453,   455,   457,
     459,   461,   463,   465,   467,   469
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     141,     0,    -1,   142,    -1,    -1,   142,   143,    -1,   144,
      -1,   145,    -1,   154,    -1,   169,    -1,   121,   134,   120,
     135,    -1,   121,   134,   119,   135,    -1,   122,   134,   105,
     135,    -1,   122,   134,   106,   135,    -1,   123,   134,   105,
     135,    -1,   123,   134,   106,   135,    -1,   124,   134,   120,
     135,    -1,   125,   134,   120,   135,    -1,   126,   134,   119,
     135,    -1,   127,   134,   119,   135,    -1,   128,   134,   119,
     135,    -1,   129,   134,   119,   135,    -1,   130,   134,   119,
     135,    -1,   131,   134,   119,   135,    -1,   132,   134,   119,
     135,    -1,   133,   134,   119,   135,    -1,   146,   153,    -1,
      -1,    73,   120,   147,   134,   148,   135,    -1,    -1,   149,
      -1,   151,    -1,   149,     4,   151,    -1,   149,     4,   150,
      -1,   150,    -1,   119,    -1,   151,     4,   152,    -1,   152,
      -1,   119,     8,   186,    -1,   136,   168,   137,    -1,   138,
      -1,    -1,   156,    62,   120,   155,   157,   158,   136,   160,
     137,    -1,    -1,    69,    -1,    70,    -1,    -1,    64,   120,
      -1,    -1,    65,   159,    -1,   159,     4,   120,    -1,   120,
      -1,    -1,   160,   161,    -1,    72,   164,   138,    -1,   162,
     166,   138,    -1,   162,   145,    -1,    -1,   162,   163,    -1,
      66,    -1,    67,    -1,    68,    -1,    71,    -1,    69,    -1,
      70,    -1,   164,     4,   165,    -1,   165,    -1,   120,     8,
     199,    -1,   166,     4,   167,    -1,   167,    -1,   119,    -1,
     119,     8,   186,    -1,    -1,   168,   169,    -1,   136,   168,
     137,    -1,   179,   138,    -1,   113,    -1,    97,   170,   138,
      -1,    98,   171,   138,    -1,    99,   134,   182,   135,   138,
      -1,    75,   138,    -1,    75,   134,   135,   138,    -1,    75,
     182,   138,    -1,    71,   172,   138,    -1,    74,   174,   138,
      -1,   101,   134,   175,   135,   138,    -1,   170,     4,   182,
      -1,   182,    -1,    -1,   134,   135,    -1,   134,   182,   135,
      -1,   172,     4,   173,    -1,   173,    -1,   119,    -1,   119,
       8,   186,    -1,   174,     4,   119,    -1,   119,    -1,   175,
       4,   176,    -1,   176,    -1,   119,    -1,    -1,   119,   177,
     178,    57,   182,   139,    -1,    -1,   178,    57,   182,   139,
      -1,    -1,   180,    -1,    -1,   180,     4,   181,   182,    -1,
     182,    -1,   134,   180,   135,    -1,    -1,    48,   183,   182,
      -1,   199,    -1,   193,    -1,   185,    -1,    -1,   184,   182,
      -1,   119,   134,   184,   135,    -1,   120,   134,   184,   135,
      -1,   185,    60,   120,   134,   184,   135,    -1,   185,    60,
     119,   134,   184,   135,    -1,   187,    -1,   199,    -1,    -1,
     103,   134,   188,   189,   135,    -1,    -1,   190,    -1,   190,
       4,    -1,   190,     4,   191,    -1,   191,    -1,   186,    -1,
     192,     9,   186,    -1,   114,    -1,   116,    -1,    -1,   103,
     134,   194,   195,   135,    -1,    -1,   196,    -1,   196,     4,
      -1,   196,     4,   197,    -1,   197,    -1,   182,    -1,   198,
       9,   182,    -1,   114,    -1,   116,    -1,   114,    -1,   115,
      -1,   116,    -1,   120,    -1,   105,    -1,   106,    -1,   107,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   203,   203,   209,   211,   217,   219,   220,   222,   228,
     229,   231,   232,   233,   234,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   252,   258,   258,   263,   265,
     266,   267,   273,   275,   280,   285,   287,   292,   297,   298,
     305,   305,   313,   314,   315,   319,   321,   325,   327,   332,
     334,   338,   340,   346,   347,   348,   352,   354,   360,   361,
     362,   363,   364,   365,   370,   372,   377,   382,   384,   389,
     390,   396,   398,   404,   406,   408,   410,   411,   412,   414,
     415,   416,   418,   419,   421,   428,   430,   434,   436,   437,
     442,   444,   449,   450,   455,   457,   462,   464,   469,   470,
     470,   475,   477,   485,   486,   491,   491,   493,   498,   500,
     500,   503,   505,   507,   513,   515,   523,   524,   525,   526,
     533,   534,   541,   541,   547,   549,   550,   555,   557,   562,
     563,   568,   569,   576,   576,   582,   584,   585,   590,   592,
     597,   598,   603,   604,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"\\316\\304\\274\\376\\316\\262 EOF\"", "error", "$undefined",
  "\"\\316\\264\\266\\250\\322\\345\\327\\326\\267\\373 UND\"", "','",
  "\"or\"", "\"xor\"", "\"and\"", "'='", "\"=>\"", "\">>=\"", "\"<<=\"",
  "\"^=\"", "\"|=\"", "\"&=\"", "\"%=\"", "\".=\"", "\"/=\"", "\"*=\"",
  "\"-=\"", "\"+=\"", "'?'", "':'", "\"||\"", "\"&&\"", "'|'", "'^'",
  "'&'", "\"<>\"", "\"!==\"", "\"===\"", "\"!=\"", "\"==\"", "'<'", "'>'",
  "\">=\"", "\"<=\"", "\">>\"", "\"<<\"", "'+'", "'-'", "'.'", "'*'",
  "'/'", "'%'", "'!'", "\"instanceof\"", "'~'", "'@'", "\"(bool)\"",
  "\"(object)\"", "\"(array)\"", "\"(string)\"", "\"(double)\"",
  "\"(int)\"", "\"--\"", "\"++\"", "'['", "\"new\"", "\"clone\"", "\"->\"",
  "\"::\"", "\"class\"", "\"interface\"", "\"extends\"", "\"implements\"",
  "\"public\"", "\"protected\"", "\"private\"", "\"final\"",
  "\"abstract\"", "\"static\"", "\"const\"", "\"function\"", "\"global\"",
  "\"return\"", "\"if\"", "\"elseif\"", "\"else\"", "\"while\"", "\"do\"",
  "\"for\"", "\"foreach\"", "\"as\"", "\"switch\"", "\"case\"",
  "\"default\"", "\"continue\"", "\"break\"", "\"try\"", "\"catch\"",
  "\"finally\"", "\"throw\"", "\"include\"", "\"include_once\"",
  "\"require\"", "\"require_once\"", "\"echo\"", "\"exit\"", "\"eval\"",
  "\"isset\"", "\"unset\"", "\"empty\"", "\"array\"", "\"list\"",
  "\"true\"", "\"false\"", "\"null\"", "\"__FUNCTION__\"", "\"__CLASS__\"",
  "\"__METHOD__\"", "\"__DIR__\"", "\"__FILE__\"",
  "\"\\304\\332\\307\\266 HTML\"", "\"\\325\\373\\312\\375 INT\"",
  "\"\\270\\241\\265\\343\\312\\375 FLOAT\"",
  "\"\\327\\326\\267\\373\\264\\256 STRING\"",
  "\"\\261\\340\\302\\353\\325\\373\\312\\375 ENC INT\"",
  "\"\\261\\340\\302\\353\\327\\326\\267\\373\\264\\256 ENC STRING\"",
  "\"\\261\\344\\301\\277 VAR\"",
  "\"\\261\\352\\312\\266\\267\\373 IDENTIFIER\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!export'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!encode'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!inline'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-wrapper'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-entry'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-heap'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-stack'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-top'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-bottom'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-exception'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-program'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-return'\"",
  "\"\\261\\340\\322\\353\\324\\323\\327\\242 '#!vm-middle'\"", "'('",
  "')'", "'{'", "'}'", "';'", "']'", "$accept", "start",
  "outer_statement_list", "outer_statement", "pragma", "define_function",
  "define_function_header", "$@1", "define_function_parameter_list",
  "define_function_parameter_required_list",
  "define_function_parameter_required",
  "define_function_parameter_optional_list",
  "define_function_parameter_optional", "define_function_body",
  "define_class", "$@2", "define_class_feature", "define_class_extends",
  "define_class_implements", "define_class_implements_list",
  "define_class_member_list", "define_class_member",
  "define_class_member_feature_list", "define_class_member_feature",
  "define_class_const_list", "define_class_const",
  "define_class_property_list", "define_class_property",
  "inner_statement_list", "inner_statement", "echo_list", "exit_code",
  "static_define_list", "static_define", "global_list",
  "unset_define_list", "unset_define", "$@3", "unset_define_array",
  "expression_list_or_empty", "expression_list", "$@4", "expression",
  "$@5", "argument_list", "call_expr", "const_expression", "const_array",
  "$@6", "const_array_define", "const_array_entry_list",
  "const_array_entry", "const_array_entry_key", "array", "$@7",
  "array_define", "array_entry_list", "array_entry", "array_entry_key",
  "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    44,   259,   260,   261,    61,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,    63,    58,   274,   275,   124,    94,    38,   276,   277,
     278,   279,   280,    60,    62,   281,   282,   283,   284,    43,
      45,    46,    42,    47,    37,    33,   285,   126,    64,   286,
     287,   288,   289,   290,   291,   292,   293,    91,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,    40,    41,   123,   125,    59,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   140,   141,   142,   142,   143,   143,   143,   143,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   145,   147,   146,   148,   148,
     148,   148,   149,   149,   150,   151,   151,   152,   153,   153,
     155,   154,   156,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   164,   164,   165,   166,   166,   167,
     167,   168,   168,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   171,   171,   171,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   177,
     176,   178,   178,   179,   179,   181,   180,   180,   182,   183,
     182,   182,   182,   182,   184,   184,   185,   185,   185,   185,
     186,   186,   188,   187,   189,   189,   189,   190,   190,   191,
     191,   192,   192,   194,   193,   195,   195,   195,   196,   196,
     197,   197,   198,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     0,     6,     0,     1,
       1,     3,     3,     1,     1,     3,     1,     3,     3,     1,
       0,     9,     0,     1,     1,     0,     2,     0,     2,     3,
       1,     0,     2,     3,     3,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     1,     1,
       3,     0,     2,     3,     2,     1,     3,     3,     5,     2,
       4,     3,     3,     3,     5,     3,     1,     0,     2,     3,
       3,     1,     1,     3,     3,     1,     3,     1,     1,     0,
       6,     0,     4,     0,     1,     0,     4,     1,     3,     0,
       3,     1,     1,     1,     0,     2,     4,     4,     6,     6,
       1,     1,     0,     5,     0,     1,     2,     3,     1,     1,
       3,     1,     1,     0,     5,     0,     1,     2,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,   109,    43,    44,     0,     0,     0,
       0,     0,    87,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,    75,   144,   145,   146,     0,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     4,     5,     6,     0,     7,
       0,     8,     0,   104,   107,   113,   112,   111,     0,    92,
       0,    91,    26,    95,     0,     0,    79,     0,     0,    86,
       0,     0,     0,     0,   133,   114,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,    71,    39,    25,     0,    74,   105,     0,   110,
       0,     0,    82,     0,     0,    83,     0,    81,     0,    76,
      88,     0,    77,     0,    98,     0,    97,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,    73,    72,   103,
      40,     0,     0,     0,     0,   147,    93,   120,   121,    90,
      28,    94,    80,    85,    89,     0,   101,     0,     0,   144,
     146,   140,     0,   136,   139,     0,   116,   115,   117,    10,
       9,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    38,    45,   106,   114,   114,
     122,    34,     0,    29,    33,    30,    36,    78,     0,    96,
      84,   134,   137,     0,     0,    47,     0,     0,   124,     0,
      27,     0,     0,     0,   138,   141,    46,     0,     0,   119,
     118,   144,   146,   129,     0,   125,   128,     0,    37,    32,
      31,     0,    35,     0,    50,    48,    51,   123,   126,     0,
     100,     0,    56,   127,   130,    49,     0,    41,    52,     0,
       0,     0,    65,    58,    59,    60,    62,    63,    61,    69,
      55,    57,     0,    68,     0,     0,    53,     0,     0,    54,
      66,    64,    70,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    45,    46,    47,    48,   103,   192,   193,
     194,   195,   196,    94,    49,   186,    50,   205,   218,   235,
     242,   248,   249,   261,   251,   252,   262,   263,    91,   138,
      68,    71,    60,    61,    64,   115,   116,   156,   198,    52,
      53,   141,    54,    58,   118,    55,   223,   147,   208,   224,
     225,   226,   227,    56,   117,   162,   163,   164,   165,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
    -123,     8,   103,  -123,  -123,  -123,  -123,   -95,   -89,   -76,
     -35,   461,   -87,   -81,   -80,   -79,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   -78,   -77,
     -75,   -73,   -71,   -67,   -65,   -51,   -40,   -34,   -32,   -30,
     -29,   -28,   -21,   461,  -123,  -123,  -123,  -123,  -122,  -123,
     -13,  -123,   -74,    54,  -123,    55,  -123,  -123,   461,    57,
       0,  -123,  -123,  -123,     1,   254,  -123,   -72,     5,  -123,
     288,   -24,   461,    -3,  -123,  -123,  -123,  -101,   -85,   -83,
      -2,     3,     9,    10,    13,    14,    15,    16,    17,    28,
       2,   172,  -123,  -123,  -123,     4,  -123,  -123,   -68,  -123,
     -70,   -95,  -123,   -17,    29,  -123,   -16,  -123,   461,  -123,
    -123,   -14,  -123,    -9,    68,    11,  -123,   482,   323,   357,
      -8,    -5,    25,    33,    36,    40,    44,    45,    46,    48,
      49,    50,    51,    52,    53,    56,  -123,  -123,  -123,   219,
    -123,   461,    30,    60,    61,  -123,  -123,  -123,  -123,  -123,
      63,  -123,  -123,  -123,  -123,    67,  -123,    -3,    69,   140,
     180,  -123,    64,   186,  -123,   189,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   157,  -123,  -123,  -123,
    -123,   230,   105,   238,  -123,   240,  -123,  -123,   188,  -123,
    -123,  -123,   482,   461,   128,   184,   392,   426,    47,   -70,
    -123,    63,   131,   461,  -123,  -123,  -123,   132,   115,  -123,
    -123,   244,   245,  -123,   120,   252,  -123,   248,  -123,  -123,
     240,   230,  -123,   119,  -123,   255,  -123,  -123,    47,   -70,
     203,   141,   -55,  -123,  -123,  -123,   142,  -123,  -123,   -41,
     256,     6,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   257,
    -123,  -123,     7,  -123,   -19,   142,  -123,   -70,   144,  -123,
    -123,  -123,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,    19,  -123,  -123,  -123,  -123,
      65,    78,    62,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,    31,  -123,    27,   174,   270,
    -123,  -123,  -123,   196,  -123,  -123,   143,  -123,  -123,  -123,
     -31,  -123,   -10,  -123,   -69,  -123,   -97,  -123,  -123,  -123,
    -123,    66,  -123,  -123,  -123,  -123,  -123,    96,  -123,   -98
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -144
static const yytype_int16 yytable[] =
{
      67,    69,   148,   146,   101,   104,    97,   119,     3,   108,
     265,   268,    90,     4,    92,   157,    93,   246,   120,   121,
     122,   123,   124,   125,    59,   253,   254,   255,   256,   257,
     258,    62,     8,   144,    90,    16,    17,    18,    19,    20,
      21,    22,    23,    63,    25,    26,    27,    70,    99,    95,
     145,   142,   143,    72,    73,    74,    75,    76,    97,    77,
     111,    78,   113,    79,    96,   100,   107,    80,    15,    81,
      16,    17,    18,    19,    20,    21,    22,    23,   259,    25,
      26,    27,   247,    82,    28,    29,    16,    17,    18,    19,
      20,    21,    22,    23,    83,    25,    26,    27,   153,    65,
      84,   145,    85,    66,    86,    87,    88,   161,   167,   167,
     148,   148,   228,    89,   112,    98,   114,   150,   126,   206,
     207,   154,   152,   127,   140,   -99,   155,   169,   128,   129,
     170,   187,   130,   131,   132,   133,   134,   136,   102,   105,
     148,   148,   244,   109,   266,   269,   158,   135,   151,  -142,
     144,     4,    16,    17,    18,    19,    20,    21,    22,    23,
     171,   221,    26,   222,   188,   -42,   270,   145,   172,   148,
     272,   173,     5,     6,     7,   174,     8,     9,    10,   175,
     176,   177,   191,   178,   179,   180,   181,   182,   183,  -143,
     202,   184,   161,   215,   189,   190,   167,   167,   203,   201,
      11,    12,    13,   233,    14,   197,    15,   200,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       4,   204,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   209,    44,
     210,  -103,   211,     7,   212,   213,     9,    10,   216,   217,
     231,   236,   234,  -131,  -132,   237,   238,   239,   240,   241,
    -102,   245,   250,   259,   264,   267,   139,     4,   260,    11,
      12,    13,    51,    14,   232,    15,   229,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   230,
       7,    28,    29,     9,    10,   273,   271,   149,   214,     0,
     199,     0,     4,     0,   243,     0,    43,     0,    44,   137,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
      14,     0,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     4,     0,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,    44,   185,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    25,    26,
      27,     4,     0,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,   106,
       0,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    25,    26,    27,     4,     0,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,   110,     0,     0,    15,     0,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    25,    26,    27,
       4,     0,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,   166,     0,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
       0,    25,    26,    27,     4,     0,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,   168,     0,     0,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    25,    26,    27,     4,
       0,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,   219,     0,    15,
       4,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      25,    26,    27,     0,     0,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,   220,     0,     0,    15,     0,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    25,    26,    27,     0,     0,
      28,    29,     0,     0,     0,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    43,   159,    26,   160,     0,
       0,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
      10,    11,   100,   100,     4,     4,     4,    76,     0,     4,
       4,     4,    43,    48,   136,     4,   138,    72,   119,   120,
     105,   106,   105,   106,   119,    66,    67,    68,    69,    70,
      71,   120,    73,   103,    65,   105,   106,   107,   108,   109,
     110,   111,   112,   119,   114,   115,   116,   134,    58,    62,
     120,   119,   120,   134,   134,   134,   134,   134,     4,   134,
      70,   134,    72,   134,   138,     8,   138,   134,   103,   134,
     105,   106,   107,   108,   109,   110,   111,   112,   119,   114,
     115,   116,   137,   134,   119,   120,   105,   106,   107,   108,
     109,   110,   111,   112,   134,   114,   115,   116,   108,   134,
     134,   120,   134,   138,   134,   134,   134,   117,   118,   119,
     208,   209,   209,   134,   138,    60,   119,   134,   120,   188,
     189,   135,   138,   120,   120,    57,   135,   135,   119,   119,
     135,   141,   119,   119,   119,   119,   119,   135,   138,   138,
     238,   239,   239,   138,   138,   138,   135,   119,   119,     9,
     103,    48,   105,   106,   107,   108,   109,   110,   111,   112,
     135,   114,   115,   116,   134,    62,   264,   120,   135,   267,
     267,   135,    69,    70,    71,   135,    73,    74,    75,   135,
     135,   135,   119,   135,   135,   135,   135,   135,   135,     9,
       4,   135,   202,   203,   134,   134,   206,   207,     9,   135,
      97,    98,    99,   213,   101,   138,   103,   138,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      48,    64,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     8,   136,
     135,   138,     4,    71,     4,    57,    74,    75,   120,    65,
     119,   136,   120,     9,     9,   135,     4,     9,   139,     4,
      57,   120,   120,   119,     8,     8,    92,    48,   249,    97,
      98,    99,     2,   101,   212,   103,   211,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   211,
      71,   119,   120,    74,    75,   268,   265,   101,   202,    -1,
     157,    -1,    48,    -1,   238,    -1,   134,    -1,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
     101,    -1,   103,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    48,    -1,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,    -1,   136,   137,   103,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,    48,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
      -1,   103,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,    48,    -1,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,    -1,    -1,   103,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
      48,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,    -1,
     103,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,    48,    -1,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,    -1,    -1,   103,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,    48,
      -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,    -1,   103,
      48,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,    -1,    -1,   103,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,    -1,    -1,
     119,   120,    -1,    -1,    -1,   103,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   134,   114,   115,   116,    -1,
      -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   141,   142,     0,    48,    69,    70,    71,    73,    74,
      75,    97,    98,    99,   101,   103,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   136,   143,   144,   145,   146,   154,
     156,   169,   179,   180,   182,   185,   193,   199,   183,   119,
     172,   173,   120,   119,   174,   134,   138,   182,   170,   182,
     134,   171,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     180,   168,   136,   138,   153,    62,   138,     4,    60,   182,
       8,     4,   138,   147,     4,   138,   135,   138,     4,   138,
     135,   182,   138,   182,   119,   175,   176,   194,   184,   184,
     119,   120,   105,   106,   105,   106,   120,   120,   119,   119,
     119,   119,   119,   119,   119,   119,   135,   137,   169,   168,
     120,   181,   119,   120,   103,   120,   186,   187,   199,   173,
     134,   119,   138,   182,   135,   135,   177,     4,   135,   114,
     116,   182,   195,   196,   197,   198,   135,   182,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   137,   155,   182,   134,   134,
     134,   119,   148,   149,   150,   151,   152,   138,   178,   176,
     138,   135,     4,     9,    64,   157,   184,   184,   188,     8,
     135,     4,     4,    57,   197,   182,   120,    65,   158,   135,
     135,   114,   116,   186,   189,   190,   191,   192,   186,   150,
     151,   119,   152,   182,   120,   159,   136,   135,     4,     9,
     139,     4,   160,   191,   186,   120,    72,   137,   161,   162,
     120,   164,   165,    66,    67,    68,    69,    70,    71,   119,
     145,   163,   166,   167,     8,     4,   138,     8,     4,   138,
     199,   165,   186,   167
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:

/* Line 1464 of yacc.c  */
#line 228 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 229 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 231 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 232 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 233 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 234 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 236 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 237 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 238 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 239 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 240 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 241 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 242 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 243 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 244 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 245 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (pragma)	(& (yyvsp[(1) - (4)]), & (yyvsp[(3) - (4)]));	;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 258 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_function_begin)	(& (yyvsp[(2) - (2)]));		;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 280 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_function_parameter_required)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 292 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_function_parameter_optional)	(& (yyvsp[(1) - (3)]));		;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 297 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_function_end)		(& (yyvsp[(1) - (3)]));		;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 298 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_function_end)		(NULL);		;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 305 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_begin)	(& (yyvsp[(3) - (3)]), & (yyvsp[(1) - (3)]));		;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 308 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_end)		( );				;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 313 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	ZR (& (yyval));	;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 314 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 315 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 321 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_extend)	(& (yyvsp[(2) - (2)]));		;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 333 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_implement)	(& (yyvsp[(3) - (3)]));		;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 334 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_implement)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 347 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_next)	( );		;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 348 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_next)	( );		;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 360 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_feature)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 361 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_feature)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 362 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_feature)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 363 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_feature)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 364 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_feature)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 365 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_feature)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 377 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_const)	(& (yyvsp[(1) - (3)]), & (yyvsp[(3) - (3)]));	;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 389 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_property)	(& (yyvsp[(1) - (1)]), NULL);	;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 390 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (define_class_property)	(& (yyvsp[(1) - (3)]), & (yyvsp[(2) - (3)]));	;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 406 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_expression)	( );	;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 408 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_html)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 411 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_exit)	( );		;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 412 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_eval)	( );		;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 414 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_return)	(NULL);		;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 415 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_return) (NULL);		;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 416 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_return) (& (yyvsp[(2) - (3)]));		;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 429 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_echo)	( );		;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 430 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_echo)	( );		;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 437 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_echo)	( );		;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 449 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_static)	(& (yyvsp[(1) - (1)]), NULL);		;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 450 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_static) (& (yyvsp[(1) - (3)]), & (yyvsp[(2) - (3)]));		;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 456 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_global)	(& (yyvsp[(1) - (3)]));		;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 457 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (statement_global)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 469 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (unset_variable)		(& (yyvsp[(1) - (1)]));		;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 470 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (unset_array_begin)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 471 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (unset_array_end)		( );		;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 478 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (unset_array_shift)	( );		;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 485 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (exprlist_empty)	( );	;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 491 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (exprlist_next)	( );	;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 500 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (expr_silent_on)	( );	;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 501 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (expr_silent_off)	( );	;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 503 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (const_expression)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 534 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (const_expression)	(& (yyvsp[(1) - (1)]));		;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 541 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (array_build)	( );	;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 562 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (array_extend)	( );		;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 563 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (array_update)	(& (yyvsp[(1) - (3)]));		;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 568 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 569 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 576 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (array_build)	( );	;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 597 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (array_extend)	( );		;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 598 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	CALL (array_update)	(& (yyvsp[(1) - (3)]));		;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 603 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 604 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 611 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 612 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 613 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 614 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 615 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 616 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 617 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 618 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 619 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 620 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 621 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 622 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.y"
    {	(yyval)	= (yyvsp[(1) - (1)]);	;}
    break;



/* Line 1464 of yacc.c  */
#line 2443 "F:\\code\\kiviuq\\php\\src\\r5\\syntax\\parser.yy.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



