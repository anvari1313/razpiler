#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kwtable.h"
#include "../util/lllist/lllist.h"

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

void symtable_init()
{
    lllist_init(&functions_list);
    lllist_init(&functions_params_list);
    temp_symbol_counter = 0;
    const_symbol_counter = 0;
}

void start_function_list()
{
    lllist_init(&functions_params_list);
}

void new_function_param(char * name, unsigned char type)
{
    Symbol s = malloc(sizeof(Symbol_t));

}

FunctionBlock new_function(char *name, unsigned char type)
{
    FunctionBlock fb = malloc(sizeof(FunctionBlock_t));
    fb->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(fb->name, name);
    fb->function_params = functions_params_list;
    fb->function_params_size = functions_params_list->size;
    fb->function_symbols_size = 0;
    fb->access_link = malloc(__ACCESS_LINK_LABEL_LEN * sizeof(char));
    sprintf(fb->access_link, "fal%d:", functions_list->size);
    llstack_init(&(fb->function_scope));
    fb->return_val = malloc(sizeof(Symbol_t));
    fb->return_val->type = type;

    lllist_push_front(functions_list, fb);

    return fb;
}

void start_scope()
{
    lllist_go_last(functions_list);
    FunctionBlock current_fb = (FunctionBlock)lllist_get_current(functions_list);

    LLList symbols_scope_list;
    lllist_init(&symbols_scope_list);

    llstack_push(current_fb->function_scope, symbols_scope_list);
}

Symbol add_symbol(char *name, unsigned char type)
{
    lllist_go_last(functions_list);
    FunctionBlock current_fb = (FunctionBlock)lllist_get_current(functions_list);

    Symbol s = malloc(sizeof(Symbol_t));
    s->id = current_fb->function_symbols_size++;
    s->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(s->name, name);
    s->type = type;

    lllist_push_front((LLList)llstack_top(current_fb->function_scope), s);
    return s;
}

void end_scope()
{
    lllist_go_last(functions_list);
    FunctionBlock current_fb = (FunctionBlock)lllist_get_current(functions_list);
    llstack_pop(current_fb->function_scope);
}

char *symbol_address(Symbol s)
{
    char *address = malloc(120 * sizeof(char));
    char *type = malloc(10 * sizeof(char));
    switch(s->type)
    {
        case SYMBOL_TYPE_BOOL:
            strcpy(type, "boolval");
            break;
        case SYMBOL_TYPE_CHAR:
            strcpy(type, "charval");
            break;
        case SYMBOL_TYPE_INT:
            strcpy(type, "intval");
            break;
        case SYMBOL_TYPE_REAL:
            strcpy(type, "floatval");
            break;
        default:                    // Default is handled by int
            strcpy(type, "intval");
    }
    sprintf(address, "top_stack()->symbols[%d].value.%s", s->id, type);
    return address;
}

char *param_address(Symbol s)
{
    char *address = malloc(120 * sizeof(char));
    char *type = malloc(10 * sizeof(char));
    switch(s->type)
    {
        case SYMBOL_TYPE_BOOL:
            strcpy(type, "boolval");
            break;
        case SYMBOL_TYPE_CHAR:
            strcpy(type, "charval");
            break;
        case SYMBOL_TYPE_INT:
            strcpy(type, "intval");
            break;
        case SYMBOL_TYPE_REAL:
            strcpy(type, "floatval");
            break;
        default:                    // Default is handled by int
            strcpy(type, "intval");
    }
    sprintf(address, "top_stack()->params[%d].value.%s", s->id, type);
    return address;
}

char *enviroment(char *name)
{
    Symbol s = search_for_symbol(name);
    if (s)
        return symbol_address(s);
    s = search_for_param(name);
    if (s)
        return param_address(s);

    return NULL;
}

Symbol search_for_symbol(char *name)
{
    Symbol result = NULL;

    lllist_go_last(functions_list);
    FunctionBlock current_fb = (FunctionBlock)lllist_get_current(functions_list);

    bool is_found = false;


    LLStack temp;
    llstack_init(&temp);

    while ((!llstack_is_empty(current_fb->function_scope))
           &&
           (!is_found))
    {
        LLList current_scope_list = llstack_top(current_fb->function_scope);
        if (current_scope_list->size != 0)
        {
            lllist_go_first(current_scope_list);
            do
            {
                Symbol s = lllist_get_current(current_scope_list);
                if (strcmp(s->name, name) == 0)
                {
                    is_found = true;
                    result = s;
                }
            }
            while (lllist_step_forward(current_scope_list));
        }

        llstack_push(temp, llstack_top_pop(current_fb->function_scope));
    }

    while (!llstack_is_empty(temp))
    {
        llstack_push(current_fb->function_scope, llstack_top_pop(temp));
    }

    return result;
}

Symbol search_for_param(char *name)
{
    Symbol result = NULL;

    lllist_go_last(functions_list);
    FunctionBlock current_fb = (FunctionBlock)lllist_get_current(functions_list);
    LLList params = current_fb->function_params;

    if (lllist_is_empty(params))
        return NULL;

    lllist_go_first(params);

    do{
        Symbol s = lllist_get_current(params);
        if (strcmp(s->name, name))
            return s;
    }while (lllist_step_forward(params));

    return NULL;
}

char *add_const_symbol(union Value value, unsigned char type) {
    char *const_symbol_name = malloc(20 * sizeof(char));
    sprintf(const_symbol_name, "c%d", const_symbol_counter ++);
    Symbol s = add_symbol(const_symbol_name, type);
    s->is_const_val = true;
    s->const_val = value;
    return enviroment(const_symbol_name);;
}

