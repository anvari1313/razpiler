//
// Created by ahmad on 11/4/17.
//

#ifndef RAZPILER_LEXER_H
#define RAZPILER_LEXER_H

#define TYPE_PROGRAM_KW '0'
#define TYPE_STRUCT_KW '1'
#define TYPE_CONST_KW '2'
#define TYPE_INTEGER_KW '3'
#define TYPE_REAL_KW '4'
#define TYPE_BOOLEAN_KW '5'
#define TYPE_CHARACTER_KW '6'
#define TYPE_IF_KW '7'
#define TYPE_THEN_KW '8'
#define TYPE_ELSE_KW '9'
#define TYPE_SWITCH_KW '10'
#define TYPE_END_KW '11'
#define TYPE_STATE_KW '12'
#define TYPE_DEFAULT_KW '13'
#define TYPE_WHEN_KW '14'
#define TYPE_RETURN_KW '15'
#define TYPE_BREAK_KW '16'

#define TYPE_OR_KW '30'
#define TYPE_AND_KW '31'
#define TYPE_NOT_KW '32'
#define TYPE_XOR_KW '33'
#define TYPE_ANDTHEN_KW '34'

#define TYPE_SEMICOLON '40'
#define TYPE_COLON '41'
#define TYPE_COMMA '42'
#define TYPE_OPEN_BRACKET '43'
#define TYPE_CLOSE_BRACKET '44'
#define TYPE_OPEN_CURLY_BRACES '45'
#define TYPE_CLOSE_CURLY_BRACES '46'


#define TYPE_LT_OP '50'
#define TYPE_GT_OP '51'
#define TYPE_EQ_OP '52'
#define TYPE_PLUS_OP '53'
#define TYPE_MINUS_OP '54'
#define TYPE_MULTIPLY_OP '55'
#define TYPE_DIVIDE_OP '56'
#define TYPE_QUESTIONMARK_OP '57'

#define TYPE_IDENTIFIER '70'
#define TYPE_NUMBER '71'
#define TYPE_CONST_CHAR '72'



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
