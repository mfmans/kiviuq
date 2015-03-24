/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


