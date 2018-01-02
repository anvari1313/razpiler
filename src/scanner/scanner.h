/**
 * Scan  from the file and make the lines to a line
 */
#ifndef RAZPILER_SCANNER_H
#define RAZPILER_SCANNER_H

#define SCAN_PATH "convert.t"
#include <stdio.h>
#include <wchar.h>
#include "type.h"

/**
 * Scan the file into lines and put it into linked list of FileLine
 * @param file_path
 * @return
 */
FileLine *scan_file(char *);
void scan(char *);

#endif //RAZPILER_SCANNER_H
