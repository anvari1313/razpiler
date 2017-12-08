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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    PROGRAM_KW = 258,
    STRUCT_KW = 259,
    CONST_KW = 260,
    INTEGER_KW = 261,
    REAL_KW = 262,
    BOOLEAN_KW = 263,
    CHARACTER_KW = 264,
    IF_KW = 265,
    THEN_KW = 266,
    ELSE_KW = 267,
    SWITCH_KW = 268,
    END_KW = 269,
    STATE_KW = 270,
    DEFAULT_KW = 271,
    WHEN_KW = 272,
    RETURN_KW = 273,
    BREAK_KW = 274,
    OR_KW = 275,
    AND_KW = 276,
    NOT_KW = 277,
    XOR_KW = 278,
    ANDTHEN_KW = 279,
    SEMICOLON = 280,
    COLON = 281,
    COMMA = 282,
    OPEN_BRACKET = 283,
    CLOSE_BRACKET = 284,
    OPEN_CURLY_BRACES = 285,
    CLOSE_CURLY_BRACES = 286,
    OPEN_PARENTHESIS = 287,
    CLOSE_PARENTHESIS = 288,
    DOT = 289,
    LT_OP = 290,
    GT_OP = 291,
    EQ_OP = 292,
    PLUS_OP = 293,
    MINUS_OP = 294,
    MULTIPLY_OP = 295,
    DIVIDE_OP = 296,
    QUESTIONMARK_OP = 297,
    PERCENT_OP = 298,
    IDENTIFIER = 299,
    NUMBER = 300,
    CONST_CHAR = 301,
    REAL_NUMBER = 302,
    BOOLEAN_FALSE = 303,
    BOOLEAN_TRUE = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
