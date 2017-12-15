#ifndef RAZPILER_SYMTABLE_H
#define RAZPILER_SYMTABLE_H

#include "../util/llstack/llstack.h"
#include "../util/lllist/lllist.h"

typedef struct {
    LLStack function_stack;
} *FunctionBlock;

LLList symbols_list;

typedef struct
{
    unsigned char symbol_type;
    char *symbol_name;
} *SymbolNode, SymbolNodeType;

void init_symbol_table();

SymbolNode install_id(char *id_name, unsigned char type);
SymbolNode search_id(char *id_name);
SymbolNode new_symbol(unsigned char symbol_type, char *symbol_name);

#endif //RAZPILER_SYMTABLE_H
