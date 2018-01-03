#ifndef RAZPILER_SYMTABLE_H
#define RAZPILER_SYMTABLE_H

#include "../util/llstack/llstack.h"
#include "../util/lllist/lllist.h"

#define __ACCESS_LINK_LABEL_LEN 50

#define SYMBOL_TYPE_BOOL 10
#define SYMBOL_TYPE_INT 20
#define SYMBOL_TYPE_REAL 30
#define SYMBOL_TYPE_CHAR 40

typedef struct {
    char *name;
    unsigned char type;
    int id;
} *Symbol, Symbol_t;

typedef struct {
    char *name;
    char *access_link;
    LLList function_params;
    int function_params_size;
    LLStack function_scope;
    int function_symbols_size;
    Symbol return_val;
} *FunctionBlock, FunctionBlock_t;

LLList functions_list;
LLList functions_params_list;

void symtable_init();
void start_function_list();
void new_function_param(char *, unsigned char);
FunctionBlock new_function(char *, unsigned char);
void start_scope();
Symbol add_symbol(char *, unsigned char);
void end_scope();
char *enviroment(char *);

///////////////////////////
LLList symbols_list;

typedef struct
{
    unsigned char symbol_type;
    char *symbol_name;
    char *symbol_id;
} *SymbolNode, SymbolNodeType;

void init_symbol_table();

SymbolNode install_id(char *id_name, unsigned char type);
SymbolNode install_temp_id(unsigned char type);
SymbolNode search_id(char *id_name);
SymbolNode new_symbol(unsigned char symbol_type, char *symbol_name);
void symbol_print();

#endif //RAZPILER_SYMTABLE_H
