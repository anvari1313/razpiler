/**
 * This file contains the struct types used in scanner
 */
#ifndef RAZPILER_TYPE_H
#define RAZPILER_TYPE_H

#include <stdio.h>
#include <wchar.h>

/**
 * Structure of the linked list of the lines to load from the file
 */
typedef struct FileLine{
    FILE *file;
    wchar_t *line_content;
    long long line_num;
    struct FileLine *next_line;
}FileLine;


/**
 * Structure of the linked list of the lexeme that lexer produce
 */
typedef struct Lexeme
{
    char *value;
    unsigned char type;
    long long column;
    FileLine *file_line;
    int symbol_table_id;
    struct Lexeme *next;
}Lexeme;


#endif //RAZPILER_TYPE_H
