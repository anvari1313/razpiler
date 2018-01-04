#include <stdlib.h>
#include <stdio.h>
#include "quad.h"
#include "bp.h"

extern LLList quad_list;

LLList bp_make_list(int i)
{
    LLList list;
    lllist_init(&list);
    int *a = malloc(sizeof(int));
    (*a) = i;
    lllist_push_front(list, a);

    return list;
}

LLList bp_merge(LLList list1, LLList list2)
{
    lllist_concat(list1, list2);
    return list1;
}

void bp_backpatch(LLList list, int i)
{
    if (! (lllist_is_empty(quad_list) || lllist_is_empty(list)))
    {
        lllist_go_first(quad_list);
        do{
            Quad q = (Quad)lllist_get_current(quad_list);
            lllist_go_first(list);
            do{
                int index = *((int *)lllist_get_current(list));
                if (q->index == index)
                {
                    q->arg4 = malloc(20 * sizeof(char));
                    sprintf(q->arg4, "%d", i);
                }
            }while(lllist_step_forward(list));
        }while (lllist_step_forward(quad_list));
    }
}