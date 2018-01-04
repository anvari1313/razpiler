#ifndef RAZPILER_QUAD_H
#define RAZPILER_QUAD_H

#include "../../util/lllist/lllist.h"

typedef struct {
    char *arg1;
    char *arg2;
    char *arg3;
    char *arg4;
    int index;
} *Quad, Quad_t;

LLList quad_list;

int quad_it;

void quad_init();
Quad quad_add(char *);
Quad quad_add4(char *, char *, char *, char *);

void quad_print();
#endif //RAZPILER_QUAD_H
