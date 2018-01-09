#include "quad.h"
#include "../../symtable/symtable.h"
#include "../error/error.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern LLList functions_list;

void quad_init()
{
    lllist_init(&quad_list);
    quad_it = 0;
    output_stack_size = DEFAULT_OUTPUT_STACK_SIZE;
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

int next_quad()
{
    return quad_it;
}

void quad_export(void (*print_function)(char *))
{
    /**
     * Exporting the header
     */
    print_function("/**\n");
    print_function(" * This code is generated by razpiler compiler(c)\n");
    print_function(" * All rights reserved By Ahmad Anvari & Mostafa Meshkati\n");
    print_function(" */\n\n\n");


    /**
     * Exporting the needed include
     */
    print_function("#include <stdbool.h>\n");
    print_function("#include <stdio.h>\n");
    print_function("#include <stdlib.h>\n\n\n");

    /**
     * Exporting function stack structs
     */
    print_function("typedef struct Symbol{\n");
    print_function("\tunion Value {\n");
    print_function("        bool boolval;\n");
    print_function("        int intval;\n");
    print_function("        char charval;\n");
    print_function("        float floatval;\n");
    print_function("    } value;\n");
    print_function(        "\n");
    print_function(        "}symbol;\n");
    print_function(        "\n");
    print_function(        "typedef struct Function{\n");
    print_function(        "    symbol *params;\n");
    print_function(        "    symbol *symbols;\n");
    print_function(        "    symbol returnval[1];\n");
    print_function(        "    char *function_name;\n");
    print_function(        "    void *access_link;\n");
    print_function(        "    void *control_link;\n");
    print_function(        "} function;\n\n");

    print_function("// Stack part");
    char stack_out_str[100];
    sprintf(stack_out_str, "function stack[%d];\n", output_stack_size);
    print_function(stack_out_str);

    print_function("int stack_pointer;\n");
    print_function("void push_stack(function f);\n");
    print_function("function pop_stack();\n");
    print_function("function *top_stack();\n");
    print_function("\n\n");

    /**
     * Export main function
     */
    print_function("int main()\n");
    print_function("{\n");

    print_function("\tunion Value function_result;\n");
    print_function("\t/**\n");
    print_function("\t* ************************************************\n");
    print_function("\t* Init the stack *********************************\n");
    print_function("     * ************************************************\n");
    print_function("     */\n");
    print_function("    stack_pointer = -1;");
    print_function("\n\n");
    print_function("\t/**\n");
    print_function("\t* ************************************************\n");
    print_function("\t* Init functions stack ***************************\n");
    print_function("\t* ************************************************\n");
    print_function("\t*/");
    print_function("\n\n");

    lllist_go_first(functions_list);

    /**
     * Export symbol table
     */
    do{
        FunctionBlock fb = lllist_get_current(functions_list);


        char f_attr_str_params[strlen(fb->name) + strlen(f_c_str_params) + 100];
        char f_attr_str_symbols[strlen(fb->name) + strlen(f_c_str_symbols) + 100];

        sprintf(f_attr_str_params, "\tint %s%s = %d;\n", fb->name, f_c_str_params, fb->function_params_size);
        sprintf(f_attr_str_symbols, "\tint %s%s = %d;\n", fb->name, f_c_str_symbols, fb->function_symbols_size);

        print_function(f_attr_str_params);
        print_function(f_attr_str_symbols);
        print_function("\n\n");

    }while(lllist_step_forward(functions_list));

    /**
     * Export pushing main to stack
     */
    FunctionBlock main_fb = function_enviroment(STARTING_POINT_FUNCTION);
    if (main_fb == NULL)
        main_not_found();

    quad_call_function(main_fb);


    lllist_go_first(quad_list);
    do{
        Quad q = lllist_get_current(quad_list);
        char *quad_label_str = quad_label_gen(q);
        char quad_str[strlen(q->arg1) + strlen(q->arg2) + strlen(q->arg3) + strlen(q->arg4) + strlen(quad_label_str) + 4];
        sprintf(quad_str, (strlen(quad_label_str) == 0)?"\t%s%s %s %s %s\n" : "%s: %s %s %s %s\n", quad_label_str, q->arg1, q->arg2, q->arg3, q->arg4);
        print_function(quad_str);
    }while (lllist_step_forward(quad_list));


    print_function("}\n");

    /**
     * Export stack functions implementations
     */

    print_function("\n\n");
    print_function("void push_stack(function f)\n");
    print_function("{\n");
    print_function("\tstack[++stack_pointer] = f;\n");
    print_function("}\n");
    print_function("\n");
    print_function("function pop_stack()\n");
    print_function("{\n");
    print_function("\treturn stack[stack_pointer--];\n");
    print_function("}\n");
    print_function("\n");
    print_function("function *top_stack()\n");
    print_function("{\n");
    print_function("\treturn &stack[stack_pointer];\n");
    print_function("}");

}

void set_output_stack_size(int s)
{
    output_stack_size = s;
}

char *quad_label_gen(Quad quad)
{
    char *label = malloc(100 * sizeof(char));

    if (quad->index == -1)
        sprintf(label, "");
    else
        sprintf(label, "l%d", quad->index);
    return label;
}

void quad_add_function_definition(FunctionBlock fb)
{
    char comment_string[strlen(fb->name) + 100];
    sprintf(comment_string, "// %s function implementation start", fb->name);
    quad_add_no_line(comment_string);
}

void quad_call_function(FunctionBlock fb)
{
    quad_add_no_line("// main function declaration");
    char function_stack_str[100];
    sprintf(function_stack_str, "%s_stack%d", fb->name, fb->call_counter);
    char function_stack_dif_str[200];
    sprintf(function_stack_dif_str, "function %s;", function_stack_str);
    quad_add_no_line(function_stack_dif_str);

    char str1[500];
    char str2[500];
    char str3[500];
    char str4[500];
    char str5[500];
    char str6[500];

    sprintf(str1, "%s.params = malloc(%s%s * sizeof(symbol));", function_stack_str, fb->name, f_c_str_params);
    quad_add_no_line(str1);
    sprintf(str2, "%s.symbols = malloc(%s%s * sizeof(symbol));", function_stack_str, fb->name, f_c_str_symbols);
    quad_add_no_line(str2);
    sprintf(str3, "%s.access_link = &&%s__;", function_stack_str, fb->access_link);
    quad_add_no_line(str3);
    sprintf(str4, "%s.control_link = &&%s%s%d;", fb->name, fb->name, FUNCITON_CONTROL_LINK_STR, fb->call_counter);
    quad_add_no_line(str4);
    sprintf(str5, "push_stack(%s);", function_stack_str);
    quad_add_no_line(str5);

    quad_add_no_line("goto *(top_stack()->access_link);");
    sprintf(str6, "%s%s%d:", fb->name, FUNCITON_CONTROL_LINK_STR, fb->call_counter);
    quad_add_no_line(str6);
}

Quad quad_add_no_line(char * str)
{
    Quad q = quad_add(str);
    q->index = -1;
    return q;
}


void qaud_add_const_symbols(FunctionBlock fb)
{
    quad_add_no_line("////// some is here is logged");
    LLList const_assignment_list = get_const_assingment_strs(fb);
    lllist_go_first(const_assignment_list);

    do{
        char *const_assignment_list_item = lllist_get_current(const_assignment_list);

        char symbol_assignment_str[strlen(const_assignment_list_item) + 100];
        sprintf(symbol_assignment_str, "\t%s;\n", const_assignment_list_item);

        quad_add_no_line(symbol_assignment_str);

    }while (lllist_step_forward(const_assignment_list));
    quad_add_no_line("////// some is here is logged");
}