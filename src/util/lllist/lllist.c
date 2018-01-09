#include <stdlib.h>
#include "lllist.h"

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
    if (lllist == NULL)
        return true;
    else
        return ((lllist->__first_node == NULL) && (lllist->__last_node == NULL)) || (lllist->size == 0);
}

void lllist_push_back(LLList lllist, LLListData lllist_data)
{
    LLListNode node = malloc(sizeof(LLListNodeType));
    node->__data = lllist_data;
    node->__ll_last = NULL;

    if (lllist->__first_node == NULL)        // List is empty
    {
        node->__ll_next = NULL;
        lllist->__last_node = node;
        lllist->__first_node = node;
        lllist->__current_node = node;
    }
    else
    {
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

    if (lllist->__last_node == NULL)        // List is empty
    {
        node->__ll_last = NULL;
        lllist->__last_node = node;
        lllist->__first_node = node;
        lllist->__current_node = node;
    }
    else
    {
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

LLListNode lllist_get_current_p(LLList lllist)
{
    return lllist->__current_node;
}

void lllist_set_current_p(LLList lllist, LLListNode lllist_node)
{
    lllist->__current_node = lllist_node;
}

bool lllist_step_forward(LLList lllist)
{
    if (lllist->__current_node == lllist->__last_node) return false;
    lllist->__current_node = lllist->__current_node->__ll_next;
    return true;
}

bool lllist_step_backward(LLList lllist)
{
    if (lllist->__current_node == lllist->__first_node) return false;
    lllist->__current_node = lllist->__current_node->__ll_last;
    return true;
}

bool lllist_is_at_last(LLList lllist)
{
    return lllist->__current_node == lllist->__last_node;
}

bool lllist_is_at_first(LLList lllist)
{
    return lllist->__current_node == lllist->__first_node;
}

void lllist_go_last(LLList lllist)
{
    lllist->__current_node = lllist->__last_node;
}

void lllist_go_first(LLList lllist)
{
    lllist->__current_node = lllist->__first_node;
}

void lllist_release(LLList *lllist)
{
    // TODO Implement the release function
}

void lllist_concat(LLList list1, LLList list2)
{
    if ((!list1) && (!list2))
        return;
    list1->__last_node->__ll_next = list2->__first_node;
    list2->__first_node->__ll_last = list1->__last_node;
    list1->size += list2->size;
    list1->__last_node = list2->__last_node;
}
