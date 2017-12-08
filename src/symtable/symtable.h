#ifndef RAZPILER_SYMTABLE_H
#define RAZPILER_SYMTABLE_H

#include "../util/llstack/llstack.h"


typedef struct {
    LLStack function_stack;
} *FunctionBlock;
#endif //RAZPILER_SYMTABLE_H
