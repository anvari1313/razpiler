#include "quad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LLList quad_list;

void quad_init()
{
    lllist_init(&quad_list);
}

void quad_add(char *code)
{
    lllist_go_last(quad_list);
    char *tcode = (char *)malloc((strlen(code) + 1) * sizeof(char));
    strcpy(tcode, code);
    lllist_push_front(quad_list, tcode);
}

void print_quad()
{
    lllist_go_first(quad_list);
    do
    {
        printf("%s\n", (char *)lllist_get_current(quad_list));
    }
    while (lllist_step_forward(quad_list) != false);
}
