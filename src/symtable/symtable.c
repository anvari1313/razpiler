#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kwtable.h"

int temp_counter;

void init_symbol_table()
{
    lllist_init(&symbols_list);
    temp_counter = 0;
    kw_add("int");
    kw_add("float");
    kw_add("main");
}

SymbolNode install_id(char *id_name, unsigned char type)
{
    if (search_id(id_name) == NULL)
    {
        SymbolNode node = new_symbol(type, id_name);
        lllist_push_front(symbols_list, node);
        return node;
    }
    else
    {
        printf("%s is used somewhere else\n", id_name);
        exit(-1);
    }
}

SymbolNode search_id(char *id_name)
{
    lllist_go_last(symbols_list);
    if (lllist_is_empty(symbols_list))
        return NULL;

    do
    {
        if (strcmp(((SymbolNode)lllist_get_current(symbols_list))->symbol_name, id_name) == 0)
            return lllist_get_current_p(symbols_list);
    }
    while (lllist_step_backward(symbols_list) != false);

    return NULL;
}

SymbolNode new_symbol(unsigned char symbol_type, char *symbol_name) {
    SymbolNode symbol_node = malloc(sizeof(SymbolNodeType));
    symbol_node->symbol_type = symbol_type;
    symbol_node->symbol_name = malloc((strlen(symbol_name) + 2) * sizeof(char));
    symbol_node->symbol_id = malloc((strlen(symbol_name) + 2) * sizeof(char));
    strcpy(symbol_node->symbol_name, symbol_name);
    strcpy(symbol_node->symbol_id, symbol_name);
//    printf("__symobol is : %s", symbol_node->symbol_id);

    return symbol_node;
}

void symbol_print()
{
    lllist_go_last(symbols_list);
    if (lllist_is_empty(symbols_list))
        return;

    do
    {
        printf("%s - %d\n", ((SymbolNode)lllist_get_current(symbols_list))->symbol_name, ((SymbolNode)lllist_get_current(symbols_list))->symbol_type);
    }
    while (lllist_step_backward(symbols_list) != false);
}

SymbolNode install_temp_id(unsigned char type)
{
    char *temp_id = (char *)malloc(20 * sizeof(char));
    sprintf(temp_id, "t%d", temp_counter++);
    return install_id(temp_id, type);
}
