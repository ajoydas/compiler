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
    IF = 258,
    FOR = 259,
    DO = 260,
    INT = 261,
    FLOAT = 262,
    VOID = 263,
    SWITCH = 264,
    DEFAULT = 265,
    ELSE = 266,
    WHILE = 267,
    BREAK = 268,
    RETURN = 269,
    CASE = 270,
    CONTINUE = 271,
    PRINTLN = 272,
    CONST_INT = 273,
    CONST_FLOAT = 274,
    CONST_CHAR = 275,
    ID = 276,
    ADDOP = 277,
    MULOP = 278,
    INCOP = 279,
    DECOP = 280,
    RELOP = 281,
    ASSINOP = 282,
    LOGICOP = 283,
    NOT = 284,
    LPAREN = 285,
    RPAREN = 286,
    LCURL = 287,
    RCURL = 288,
    LTHIRD = 289,
    RTHIRD = 290,
    COMMA = 291,
    SEMICOLON = 292,
    SINGLECOM = 293,
    MULTICOM = 294,
    only_if = 295
  };
#endif
/* Tokens.  */
#define IF 258
#define FOR 259
#define DO 260
#define INT 261
#define FLOAT 262
#define VOID 263
#define SWITCH 264
#define DEFAULT 265
#define ELSE 266
#define WHILE 267
#define BREAK 268
#define RETURN 269
#define CASE 270
#define CONTINUE 271
#define PRINTLN 272
#define CONST_INT 273
#define CONST_FLOAT 274
#define CONST_CHAR 275
#define ID 276
#define ADDOP 277
#define MULOP 278
#define INCOP 279
#define DECOP 280
#define RELOP 281
#define ASSINOP 282
#define LOGICOP 283
#define NOT 284
#define LPAREN 285
#define RPAREN 286
#define LCURL 287
#define RCURL 288
#define LTHIRD 289
#define RTHIRD 290
#define COMMA 291
#define SEMICOLON 292
#define SINGLECOM 293
#define MULTICOM 294
#define only_if 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
