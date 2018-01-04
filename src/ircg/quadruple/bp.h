#include "../../util/lllist/lllist.h"

#ifndef RAZPILER_BP_H
#define RAZPILER_BP_H

LLList bp_make_list(int i);
LLList bp_merge(LLList, LLList);
void bp_backpatch(LLList, int i);

#endif //RAZPILER_BP_H
