#ifndef RAZPILER_QUAD_H
#define RAZPILER_QUAD_H

#include "../../util/lllist/lllist.h"
#include "../../symtable/symtable.h"

#define DEFAULT_OUTPUT_STACK_SIZE 100
#define STARTING_POINT_FUNCTION "BRbg"

#define _QUAD_LABEL_PATTERN "l%d"

#define f_c_str_params "_function_params_size"
#define f_c_str_symbols "_function_symbols_size"

#define FUNCITON_CONTROL_LINK_STR "_RETURN_BACK"

typedef struct {
    char *arg1;
    char *arg2;
    char *arg3;
    char *arg4;
    int index;
} *Quad, Quad_t;

LLList quad_list;

int output_stack_size;

int quad_it;

void quad_init();
Quad quad_add(char *);
Quad quad_add_no_line(char *);
Quad quad_add4(char *, char *, char *, char *);
void quad_call_function(FunctionBlock);
void quad_call_function_main();
void quad_add_function_definition(FunctionBlock);
int next_quad();
void set_output_stack_size(int);
void quad_print();
void quad_export(void (*print_function)(char *));
char *quad_label_gen(Quad);
void qaud_add_const_symbols(FunctionBlock);

#endif //RAZPILER_QUAD_H
