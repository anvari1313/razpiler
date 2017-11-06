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

int func();

#endif //RAZPILER_LEXER_H
