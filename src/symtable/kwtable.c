#include <stdlib.h>
#include <string.h>
#include "kwtable.h"
#include <stdio.h>

/**
 * Linked List implementation:
 * The first node is valid node and has valid data
 */

KWTableNode first = NULL;
KWTableNode last = NULL;

void add_kw(char *token)
{
    if (first == NULL)
    {
        first = malloc(sizeof(KWTableNode));
        first->token = token;
        first->next = NULL;
        last = first;
    }
    else
    {
        last->next = malloc(sizeof(KWTableNode));
        last = last->next;
        last->token = token;
        last->next = NULL;
    }
}
bool search(char *token)
{
    KWTableNode current = first;
    while (current)
    {
        if (strcmp(current->token, token) == 0)
            return true;
        else
            current = current->next;
    }

    return false;
}