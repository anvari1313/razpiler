/**
 * Scan  from the file and make the lines to a line
 */
#ifndef RAZPILER_SCANNER_H
#define RAZPILER_SCANNER_H

#include <stdio.h>
#include <wchar.h>

/**
 * Structure of the lines to load from the file
 */
typedef struct FileLine{
    FILE *file;
    wchar_t *line_content;
    long long line_num;
    struct FileLine *next_line;
}FileLine;

/**
 * Scan the file into lines and put it into linked list of FileLine
 * @param file_path
 * @return
 */
FileLine *scan_file(char *);



#endif //RAZPILER_SCANNER_H
