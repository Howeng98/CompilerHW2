/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    VAR = 258,
    ADD = 259,
    SUB = 260,
    MUL = 261,
    QUO = 262,
    REM = 263,
    INT = 264,
    FLOAT = 265,
    BOOL = 266,
    STRING = 267,
    INC = 268,
    DEC = 269,
    GEQ = 270,
    LEQ = 271,
    EQL = 272,
    NEQ = 273,
    LST = 274,
    GTR = 275,
    ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    MUL_ASSIGN = 279,
    QUO_ASSIGN = 280,
    REM_ASSIGN = 281,
    LAND = 282,
    LOR = 283,
    NOT = 284,
    NEWLINE = 285,
    SEMICOLON = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    FOR = 290,
    PRINT = 291,
    PRINTLN = 292,
    TRUE = 293,
    FALSE = 294,
    INT_LIT = 295,
    FLOAT_LIT = 296,
    STRING_LIT = 297,
    IDENT = 298
  };
#endif
/* Tokens.  */
#define VAR 258
#define ADD 259
#define SUB 260
#define MUL 261
#define QUO 262
#define REM 263
#define INT 264
#define FLOAT 265
#define BOOL 266
#define STRING 267
#define INC 268
#define DEC 269
#define GEQ 270
#define LEQ 271
#define EQL 272
#define NEQ 273
#define LST 274
#define GTR 275
#define ASSIGN 276
#define ADD_ASSIGN 277
#define SUB_ASSIGN 278
#define MUL_ASSIGN 279
#define QUO_ASSIGN 280
#define REM_ASSIGN 281
#define LAND 282
#define LOR 283
#define NOT 284
#define NEWLINE 285
#define SEMICOLON 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define FOR 290
#define PRINT 291
#define PRINTLN 292
#define TRUE 293
#define FALSE 294
#define INT_LIT 295
#define FLOAT_LIT 296
#define STRING_LIT 297
#define IDENT 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "compiler_hw2.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 150 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
