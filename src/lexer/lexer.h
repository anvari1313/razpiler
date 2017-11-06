//
// Created by ahmad on 11/4/17.
//

#ifndef RAZPILER_LEXER_H
#define RAZPILER_LEXER_H

#define TYPE_PROGRAM_KW 0
#define TYPE_STRUCT_KW 1
#define CONST_KW 2
#define INTEGER_KW 3
#define REAL_KW 4
#define BOOLEAN_KW 5
#define CHARACTER_KW 6
#define IF_KW 7
#define THEN_KW 8
#define ELSE_KW 9
#define SWITCH_KW 10
#define END_KW 11
#define STATE_KW 12
#define DEFAULT_KW 13
#define WHEN_KW 14
#define RETURN_KW 15
#define BREAK_KW 16

#define OR_KW 30
#define AND_KW 31
#define NOT_KW 32
#define XOR_KW 33
#define ANDTHEN_KW 34

#define SEMICOLON 40
#define COLON 41
#define COMMA 42

#define LT_OP 50
#define GT_OP 51
#define EQ_OP 52
#define PLUS_OP 53
#define MINUS_OP 54
#define MULTIPLY_OP 55
#define DIVIDE_OP 56
#define QUESTIONMARK_OP 57

#include "scanner.h"

typedef struct Lexeme
{
    char *value;
    unsigned char type;
    long long column;
    FileLine *file_line;
    int symbol_table_id;
    struct Lexeme *next;
}Lexeme;

Lexeme *output = NULL;
Lexeme *current_lexeme_pointer = NULL;

int func(char *string, FileLine *fileLine);

#endif //RAZPILER_LEXER_H
