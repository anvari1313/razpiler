#ifndef RAZPILER_PP_H
#define RAZPILER_PP_H

#include <wchar.h>
#include "scanner.h"

char map_to_english(wchar_t c);
char *preprocess_line(FileLine *file_line);

#endif //RAZPILER_PP_H
