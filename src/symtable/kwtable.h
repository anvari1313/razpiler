/**
 * This module will build up a linked list and full it with keywords of
 * the language to search when defining new identifier name
 */
#ifndef RAZPILER_KWTABLE_H
#define RAZPILER_KWTABLE_H

#include <stdbool.h>

struct KWTableStruct{
    char *token;
    struct KWTableStruct *next;
};

typedef struct KWTableStruct *KWTableNode;

void add_kw(char *);
bool search(char *);

#endif //RAZPILER_KWTABLE_H
