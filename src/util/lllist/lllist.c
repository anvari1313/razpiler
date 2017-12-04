#include "lllist.h"
#include <malloc.h>

void lllist_init(LLList *lllist)
{
    (*lllist) = malloc(sizeof(LLListType));
    (*lllist)->size = 0;
    (*lllist)->__last_node =
    (*lllist)->__current_node =
    (*lllist)->__first_node = NULL;
}

bool lllist_is_empty(LLList lllist)
{
    return ((lllist->__first_node == NULL) && (lllist->__last_node == NULL)) || (lllist->size == 0);
}

void lllist_push_back(LLList lllist, LLListData lllist_data)
{
    LLListNode node = malloc(sizeof(LLListNodeType));
    node->__data = lllist_data;
    node->__ll_last = NULL;

    printf("tr:%d\n", (*(int *)node->__data));
    if (lllist->__first_node == NULL)        // List is empty
    {
        printf("First is added\n");
        node->__ll_next = NULL;
        lllist->__last_node = node;
        lllist->__first_node = node;
        lllist->__current_node = node;
    }
    else
    {
        printf("Next is added\n");
        node->__ll_next = lllist->__first_node;
        lllist->__first_node->__ll_last = node;
        lllist->__first_node = node;
    }

    lllist->size ++;
}

void lllist_push_front(LLList lllist, LLListData lllist_data)
{
    LLListNode node = malloc(sizeof(LLListNodeType));
    node->__data = lllist_data;
    node->__ll_next = NULL;

    printf("tr:%d\n", (*(int *)node->__data));
    if (lllist->__last_node == NULL)        // List is empty
    {
        printf("First is added\n");
        node->__ll_last = NULL;
        lllist->__last_node = node;
        lllist->__first_node = node;
        lllist->__current_node = node;
    }
    else
    {
        printf("Next is added\n");
        node->__ll_last = lllist->__last_node;
        lllist->__last_node->__ll_next = node;
        lllist->__last_node = node;
    }

    lllist->size ++;
}

LLListData lllist_get_current(LLList lllist)
{
    return lllist->__current_node->__data;
}

void lllist_step_forward(LLList lllist)
{
    lllist->__current_node = lllist->__current_node->__ll_next;
}

void lllist_step_backward(LLList lllist)
{
    lllist->__current_node = lllist->__current_node->__ll_last;
}

bool lllist_is_at_last(LLList lllist)
{
    return lllist->__current_node == lllist->__last_node;
}

bool lllist_is_at_first(LLList lllist)
{
    return lllist->__current_node == lllist->__first_node;
}