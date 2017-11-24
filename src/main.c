#include <stdlib.h>
#include "scanner/scanner.h"
#include <wchar.h>
#include "scanner/pp.h"
#include <locale.h>


int main()
{

    char *locale = setlocale(LC_ALL, "");       // Set the locale for reading the persian characters
    FileLine *start = scan_file("/home/ahmad/Desktop/input2.txt");
//    FileLine *current = start->next_line;
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


//    build_f2e_bst();

    return EXIT_SUCCESS;
}