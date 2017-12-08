#ifndef RAZPILER_EXP_H
#define RAZPILER_EXP_H

#include <string.h>
#include "../util/lllist/lllist.h"

typedef struct {
    char *code;
    LLList true_list;
    LLList false_list;
    char *place;
    char *value;
} *Expression, ExpressionType;

void exp_init(Expression *);
void exp_set_place(Expression);

#endif //RAZPILER_EXP_H
