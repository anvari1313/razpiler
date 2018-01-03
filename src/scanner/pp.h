/**
 * This file contains the pre process action. For razpiler the pre process contains
 * - Read each given string and convert the farsi characters to their english equivalent
 */
#ifndef RAZPILER_PP_H
#define RAZPILER_PP_H

#include <wchar.h>
#include "scanner.h"

#define FILE_PATH_E2F_CHARSET "/home/ahmad/CLionProjects/razpiler/resource/charset-e2f.map"
#define FILE_PATH_F2E_CHARSET "/home/ahmad/CLionProjects/razpiler/resource/charset-f2e.map"

void build_f2e_bst();   // Build the bst for mapping farsi characters to english from the table in file
void build_e2f_bst();   // Build the bst for mapping english characters to farsi from the table in file

//typedef struct CharMapBSTNode{
//    wchar_t f_char;                     // Represent the farsi character
//    char e_char;                        // Represent the english character
//    struct CharMapBSTNode *right_child; // Right child pointer in bst
//    struct CharMapBSTNode *left_child;  // Left child pointer in bst
//} CharMapBSTNode;

char map_to_english(wchar_t c);
char *preprocess_line(FileLine *file_line);

#endif //RAZPILER_PP_H
