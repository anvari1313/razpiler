#ifndef RAZPILER_SYMTABLE_H
#define RAZPILER_SYMTABLE_H

#include "../util/llstack/llstack.h"
#include "../util/lllist/lllist.h"

#define SYMBOL_TYPE_BOOL 10
#define SYMBOL_TYPE_INT 20
#define SYMBOL_TYPE_REAL 30
#define SYMBOL_TYPE_CHAR 40

typedef struct {
    LLStack function_stack;
} *FunctionBlock;

LLList symbols_list;

typedef struct
{
    unsigned char symbol_type;
    char *symbol_name;
    char *symbol_id;
} *SymbolNode, SymbolNodeType;

void init_symbol_table();

SymbolNode install_id(char *id_name, unsigned char type);
SymbolNode search_id(char *id_name);
SymbolNode new_symbol(unsigned char symbol_type, char *symbol_name);
void symbol_print();

#endif //RAZPILER_SYMTABLE_H
