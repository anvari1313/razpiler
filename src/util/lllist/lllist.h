/**
 * Linked list implementation of Two-way List
 * General purpose with void
 * This list is not random accessible and new item just can be added to the
 * back and front of the list.
 */
#include <stdbool.h>
#include <glob.h>

#ifndef RAZPILER_LLLIST_H
#define RAZPILER_LLLIST_H

typedef void *LLListData;

typedef struct LLListNode{
    LLListData __data;
    struct LLListNode *__ll_last;
    struct LLListNode *__ll_next;
} LLListNodeType, *LLListNode;


typedef struct {
    LLListNode __first_node;
    LLListNode __current_node;
    LLListNode __last_node;
    size_t size;
} *LLList, LLListType;

/**
 * Initial the data structure of list container
 * @param lllist The list container
 */
void lllist_init(LLList *);

/**
 * Returns whether the list is empty or not
 * @param lllist The list to be checked if it is empty or not
 * @return The emptiness of the list
 */
bool lllist_is_empty(LLList);

/**
 * Returns whether the current of list is at last or not
 * @param lllist The list to be checked if it is empty or not
 * @return The emptiness of the list
 */
bool lllist_is_at_last(LLList);

/**
 * Returns whether the current of list is at first or not
 * @param lllist The list to be checked if it is empty or not
 * @return The emptiness of the list
 */
bool lllist_is_at_first(LLList);

/**
 *
 * @param lllist
 * @param lllist_data
 */
void lllist_push_back(LLList, LLListData);

/**
 *
 * @param lllist
 * @param llList_data
 */
void lllist_push_front(LLList, LLListData);

/**
 * Get
 * @param lllist
 * @return
 */
LLListData lllist_get_current(LLList);

/**
 *
 * @param lllist
 */
void lllist_step_forward(LLList);

/**
 *
 * @param lllist
 */
void lllist_step_backward(LLList);

/**
 * Release the resources allocated to the lllist
 * @param lllist The lllist that should be un allocate from the memory
 */
void lllist_release(LLList);

#endif //RAZPILER_LLLIST_H