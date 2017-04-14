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
    INTEGER = 258,
    REAL = 259,
    FUNCTION = 260,
    PROCEDURE = 261,
    DOTDOT = 262,
    COLON = 263,
    VAR = 264,
    ARRAY = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    DO = 269,
    WHILE = 270,
    WRITE = 271,
    PROGRAM = 272,
    OF = 273,
    ID = 274,
    SEMICOLON = 275,
    COMMA = 276,
    BEGIN1 = 277,
    END = 278,
    NUM = 279,
    ASSIGNOP = 280,
    RELOP = 281,
    ADDOP = 282,
    NOT = 283,
    MULOP = 284,
    PAREN1 = 285,
    PAREN2 = 286,
    BRACKET1 = 287,
    BRACKET2 = 288,
    OR = 289,
    AND = 290,
    CURLEY1 = 291,
    CURLEY2 = 292,
    ADDOP1 = 293,
    ADDOP2 = 294,
    MULOP1 = 295,
    MULOP2 = 296,
    IFX = 297
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define REAL 259
#define FUNCTION 260
#define PROCEDURE 261
#define DOTDOT 262
#define COLON 263
#define VAR 264
#define ARRAY 265
#define IF 266
#define THEN 267
#define ELSE 268
#define DO 269
#define WHILE 270
#define WRITE 271
#define PROGRAM 272
#define OF 273
#define ID 274
#define SEMICOLON 275
#define COMMA 276
#define BEGIN1 277
#define END 278
#define NUM 279
#define ASSIGNOP 280
#define RELOP 281
#define ADDOP 282
#define NOT 283
#define MULOP 284
#define PAREN1 285
#define PAREN2 286
#define BRACKET1 287
#define BRACKET2 288
#define OR 289
#define AND 290
#define CURLEY1 291
#define CURLEY2 292
#define ADDOP1 293
#define ADDOP2 294
#define MULOP1 295
#define MULOP2 296
#define IFX 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
