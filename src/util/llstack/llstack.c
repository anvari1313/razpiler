#include <stdlib.h>
#include <memory.h>
#include "llstack.h"

void llstack_init(LLStack *llstack)
{
    (*llstack) = malloc(sizeof(LLStackType));
    (*llstack)->__start_node = (*llstack)->__last_node = NULL;
    (*llstack)->size = 0;
}

void llstack_push(LLStack llstack, LLStackData llstack_data)
{
    if (llstack->__start_node == NULL)          // Stack is empty
    {
        LLStackNode node = malloc(sizeof(LLStackNodeType));
//        memcpy(node->__data, llstack_data, sizeof((llstack_data)));
        node->__data = llstack_data;
        node->__ll_last = NULL;
        llstack->__start_node = llstack->__last_node = node;
    }
    else
    {
        LLStackNode node = malloc(sizeof(LLStackNodeType));
//        memcpy(node->__data, llstack_data, sizeof((llstack_data)));
        node->__data = llstack_data;
        node->__ll_last = llstack->__last_node;
        llstack->__last_node = node;
    }

    llstack->size ++;
}

void llstack_pop(LLStack llstack)
{
    if (llstack->__start_node != NULL)
    {
//        free(llstack->__last_node->__data);     // Free the data section
        if (llstack->__last_node == llstack->__start_node)
        {
            free(llstack->__last_node);
            llstack->__start_node = llstack->__last_node = NULL;
        }
        else
        {
            LLStackNode last_node = llstack->__last_node->__ll_last;
            free(llstack->__last_node);
            llstack->__last_node = last_node;
        }

        llstack->size --;
    }
}

LLStackData llstack_top(LLStack llstack)
{
    return llstack->__last_node->__data;
}

LLStackData llstack_top_pop(LLStack llstack)
{
    LLStackData data = llstack_top(llstack);
    llstack_pop(llstack);
    return data;
}

void llstack_release(LLStack llstack)
{
    // TODO implement this part
}

bool llstack_is_empty(LLStack llstack) {
    return ((llstack->__last_node == llstack->__start_node) && (llstack->__last_node == NULL)) || (llstack->size == 0);
}
