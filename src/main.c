#include <stdlib.h>
#include <stdio.h>
#include "scanner/scanner.h"
#include <wchar.h>
//#include "scanner/pp.h"
#include <locale.h>
#include <string.h>
#include <zconf.h>
#include "symtable/symtable.h"
//#include "util/llstack/llstack.h"
//#include "util/lllist/lllist.h"
#include "ircg/quadruple/quad.h"
#include "scanner/pp.h"

extern LLList lexeme_list;

extern void parse_file(char *path);


int main()
{
    const char *file_path = "/home/ahmad/CLionProjects/razpiler/resource/input2.raz";
    scan(file_path);

    init_symbol_table();
    quad_init();
    parse_file(SCAN_PATH);

    return EXIT_SUCCESS;
}
//int main() {
////    add_kw("insert");
////    add_kw("test");
////    add_kw("me");
////    printf("%d\n", search("test"));
////    printf("%d\n", search("r"));
////    printf("%d\n", search("me"));
////    printf("%d\n", search("insert"));
//
//
//
//    char *locale = setlocale(LC_ALL, "");       // Set the locale for reading the persian characters
//
//    wprintf(L"-------------------------------------------\n");
////    wprintf(L"%s", r);
//    FileLine *start = scan_file("/home/ahmad/CLionProjects/razpiler/resource/input2.raz");
//    FileLine *current = start->next_line;
////
////    while (lllist_step_forward(lexeme_list))
////    {
////        wprintf(L"------------------------------------***------------\n");
////        wprintf(L"%s\n", (char *)lllist_get_current(lexeme_list));
////    }
////
//    FILE *ouput = fopen("/home/ahmad/CLionProjects/razpiler/t.raz", "w");
//    while(current != NULL)
//    {
//        wprintf(L"%d ", wcslen(current->line_content));
//        char *str = preprocess_line(current);
//        fprintf(ouput, "%s\n", str);
//        wprintf(L"%d\n", strlen(str));
////        wprintf(L"--%ls--|--%s--\n", current->line_content, str);
////        wprintf(L"--%ls--|(%d)\n", current->line_content, wcslen(current->line_content));
////        wprintf(L"new line\n");
//
////        func(str, NULL);
//        current = current->next_line;
//    }
////
//    /**
//     *
//     * /**/
//
//
////    build_f2e_bst();
//
//    init_symbol_table();
//    quad_init();
////    quad_add("This");
////    quad_add("That");
////    quad_add("We");
////    print_quad();
//
//    parse_file("/home/ahmad/CLionProjects/razpiler/resource/input.raz");
//    printf("\n\n\n\n\n");
//    printf("Symbol table :\n");
//    symbol_print();
//    print_quad();
//
////    FILE *f = fopen("/home/ahmad/CLionProjects/razpiler/resource/input.raz", "r");
////    wchar_t * buffer = 0;
////    long length;
////
////    if (f)
////    {
////        fseek (f, 0, SEEK_END);
////        length = ftell (f);
////        fseek (f, 0, SEEK_SET);
////        buffer = malloc (length);
////        if (buffer)
////        {
////            fread (buffer, 1, length, f);
////            wprintf(L"%ls\n", buffer);
////        }
////        fclose (f);
////    }
//    wprintf(L"%ls\n", L"این متن است");
//
//
////    install_id("t", 1);
////    install_id("res", 1);
////    install_id("we", 13);
////
//
////
////    if (search_id("res") == NULL)
////        printf("res is not found\n");
////
////    if (search_id("she") == NULL)
////        printf("she is not found\n");
//
//    system("pwd");
//    system("java Converter");
//    return EXIT_SUCCESS;
//}