/**
 * Linked list implementation of Stack
 * General purpose with void
 */
#ifndef RAZPILER_LLSTACK_H
#define RAZPILER_LLSTACK_H

#include <stdbool.h>

typedef void *LLStackData;

typedef struct LLStackNode{
    LLStackData __data;
    struct LLStackNode *__ll_last;
} *LLStackNode, LLStackNodeType;

typedef struct {
    LLStackNode __start_node;
    LLStackNode __last_node;
    size_t size;
} *LLStack, LLStackType;

/**
 * Initial the data structure of stack container
 * @param llstack The stack container
 */
void llstack_init(LLStack *);

/**
 * Push action in the stack
 * @param llstack The stack to be pushed to
 * @param llstack_data The data that should be pushed to the stack
 */
void llstack_push(LLStack, LLStackData);

/**
 * Pop action from the stack
 * @param llstack The stack that should be popped from
 */
void llstack_pop(LLStack);

/**
 * Top element of the stack
 * @param llstack The stack that the top element is needed
 * @return The top element of the stack
 */
LLStackData llstack_top(LLStack);

/**
 * Get the top element of the stack and pop it!
 * @param llstack The stack that top_pop is needed
 * @return The top element of the stack
 */
LLStackData llstack_top_pop(LLStack);

/**
 * Returns whether the stack is empty or not
 * @param llstack The stack to be checked if it is empty or not
 * @return The emptiness of the stack
 */
bool llstack_is_empty(LLStack);

/**
 * Release the resources allocated to the llstack
 * @param llstack The llstack that should be un allocate from the memory
 */
void llstack_release(LLStack);

#endif //RAZPILER_LLSTACK_H
