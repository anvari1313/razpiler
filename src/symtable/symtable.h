#ifndef RAZPILER_SYMTABLE_H
#define RAZPILER_SYMTABLE_H

#include "../util/llstack/llstack.h"
#include "../util/lllist/lllist.h"

#define __const_symtable_segment_link_pattern "CONST_SEGMENT_%d"
#define __const_symtable_segment_return_link_pattern "CONST_SEGMENT_RETURN_%d"

#define __ACCESS_LINK_LABEL_LEN 50

#define SYMBOL_TYPE_VOID 0
#define SYMBOL_TYPE_BOOL 10
#define SYMBOL_TYPE_CHAR 20
#define SYMBOL_TYPE_INT 30
#define SYMBOL_TYPE_REAL 40


union Value {
    bool boolval;
    int intval;
    float floatval;
    char charval;
};

typedef struct {
    char *name;
    unsigned char type;
    int id;
    union Value const_val;
    bool is_const_val;
} *Symbol, Symbol_t;

int function_counter;

typedef struct {
    char *name;
    char *access_link;
    char *const_symtable_segment_link;
    char *const_symtable_segment_return_link;
    int call_counter;
    LLList function_params;
    int function_params_size;
    LLStack function_scope;
    int function_symbols_size;
    Symbol return_val;
    LLList constant_symbols;
} *FunctionBlock, FunctionBlock_t;

LLList functions_list;
LLList functions_params_list;

int temp_symbol_counter;
int const_symbol_counter;

void symtable_init();
void start_function_list();
void new_function_param(char *, unsigned char);
FunctionBlock new_function(char *, unsigned char);
FunctionBlock function_enviroment(char *);
void start_scope();
Symbol add_symbol(char *, unsigned char);
Symbol add_temp_symbol(unsigned char);
char *symbol_address(Symbol s);
char *add_const_symbol(union Value value, unsigned char);
void end_scope();
Symbol search_for_symbol(char *);
Symbol search_for_param(char *);
char *enviroment(char *);
LLList get_const_assingment_strs(FunctionBlock fb);

///////////////////////////
LLList symbols_list;

typedef struct
{
    unsigned char symbol_type;
    char *symbol_name;
    char *symbol_id;
} *SymbolNode, SymbolNodeType;

void init_symbol_table();

//SymbolNode install_id(char *id_name, unsigned char type);
SymbolNode install_temp_id(unsigned char type);
SymbolNode search_id(char *id_name);
SymbolNode new_symbol(unsigned char symbol_type, char *symbol_name);
void symbol_print();

#endif //RAZPILER_SYMTABLE_H
