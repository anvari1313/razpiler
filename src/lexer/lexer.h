//
// Created by ahmad on 11/4/17.
//

#ifndef RAZPILER_LEXER_H
#define RAZPILER_LEXER_H

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
