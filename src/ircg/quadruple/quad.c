#include "quad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void quad_init()
{
    lllist_init(&quad_list);
    quad_it = 0;
}

Quad quad_add(char *code)
{
    lllist_go_last(quad_list);
    Quad q = malloc(sizeof(Quad_t));
    q->index = quad_it++;

    q->arg1 = (char *)malloc((strlen(code) + 1) * sizeof(char));
    q->arg2 = (char *)malloc(1 * sizeof(char));
    q->arg3 = (char *)malloc(1 * sizeof(char));
    q->arg4 = (char *)malloc(1 * sizeof(char));
    strcpy(q->arg1, code);
    q->arg2[0] = q->arg3[0] = q->arg4[0] = '\0';

    lllist_push_front(quad_list, q);

    return q;
}

Quad quad_add4(char *arg1, char *arg2, char *arg3, char *arg4)
{
    lllist_go_last(quad_list);
    Quad q = malloc(sizeof(Quad_t));
    q->index = quad_it++;

    q->arg1 = (char *)malloc((strlen(arg1) + 1) * sizeof(char));
    q->arg2 = (char *)malloc((strlen(arg2) + 1) * sizeof(char));
    q->arg3 = (char *)malloc((strlen(arg3) + 1) * sizeof(char));
    q->arg4 = (char *)malloc((strlen(arg4) + 1) * sizeof(char));
    strcpy(q->arg1, arg1);
    strcpy(q->arg2, arg2);
    strcpy(q->arg3, arg3);
    strcpy(q->arg4, arg4);

    lllist_push_front(quad_list, q);

    return q;
}
void quad_print()
{
    lllist_go_first(quad_list);
    do
    {
        Quad q = (Quad)lllist_get_current(quad_list);
        printf("%d : %s %s %s %s\n", q->index, q->arg1, q->arg2, q->arg3, q->arg4);
    }
    while (lllist_step_forward(quad_list) != false);
}
