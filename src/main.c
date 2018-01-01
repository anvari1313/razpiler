#include <stdlib.h>
#include <stdio.h>
#include "scanner/scanner.h"
//#include <wchar.h>
//#include "scanner/pp.h"
#include <locale.h>
#include "symtable/symtable.h"
//#include "util/llstack/llstack.h"
//#include "util/lllist/lllist.h"
#include "ircg/quadruple/quad.h"

extern LLList lexeme_list;

extern void parse_file(char *path);

int main() {
//    add_kw("insert");
//    add_kw("test");
//    add_kw("me");
//    printf("%d\n", search("test"));
//    printf("%d\n", search("r"));
//    printf("%d\n", search("me"));
//    printf("%d\n", search("insert"));



//    char *locale = setlocale(LC_ALL, "");       // Set the locale for reading the persian characters
    char r[20];
    sprintf(r, "L%d", 12);
//    wprintf(L"-------------------------------------------\n");
//    wprintf(L"%s", r);
//    FileLine *start = scan_file("/Users/invisible/Desktop/input2 (1).txt");
//    FileLine *current = start->next_line;
//
//    while (lllist_step_forward(lexeme_list))
//    {
//        wprintf(L"------------------------------------***------------\n");
//        wprintf(L"%s\n", (char *)lllist_get_current(lexeme_list));
//    }
//
//    while(current != NULL)
//    {
//
//        char *str = preprocess_line(current);
//        wprintf(L"00%s00\n", str);
////        wprintf(L"--%ls--|--%s--\n", current->line_content, str);
////        func(str, NULL);
//        current = current->next_line;
//    }
//
    /**
     *
     * /**/


//    build_f2e_bst();

    init_symbol_table();
    quad_init();
//    quad_add("This");
//    quad_add("That");
//    quad_add("We");
//    print_quad();

    parse_file("/home/ahmad/CLionProjects/razpiler/resource/input.raz");
    printf("\n\n\n\n\n");
    printf("Symbol table :\n");
    symbol_print();
    print_quad();

//    install_id("t", 1);
//    install_id("res", 1);
//    install_id("we", 13);
//

//
//    if (search_id("res") == NULL)
//        printf("res is not found\n");
//
//    if (search_id("she") == NULL)
//        printf("she is not found\n");
    return EXIT_SUCCESS;
}