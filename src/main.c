#include <stdlib.h>
#include <stdio.h>
#include "scanner/scanner.h"
//#include <wchar.h>
//#include "scanner/pp.h"
#include <locale.h>
//#include "symtable/kwtable.h"
#include "util/llstack/llstack.h"
#include "util/lllist/lllist.h"

int *f(int a)
{
    int *r = malloc(4);
    (*r) = a;
    return r;
}

extern LLList lexeme_list;

int main() {
//    add_kw("insert");
//    add_kw("test");
//    add_kw("me");
//    printf("%d\n", search("test"));
//    printf("%d\n", search("r"));
//    printf("%d\n", search("me"));
//    printf("%d\n", search("insert"));



    char *locale = setlocale(LC_ALL, "");       // Set the locale for reading the persian characters
    wprintf(L"-------------------------------------------\n");
    FileLine *start = scan_file("/home/ahmad/Desktop/input2.txt");
    FileLine *current = start->next_line;

    while (lllist_step_forward(lexeme_list))
    {
        wprintf(L"------------------------------------***------------\n");
        wprintf(L"%s\n", (char *)lllist_get_current(lexeme_list));
    }
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

    return EXIT_SUCCESS;
}