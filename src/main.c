#include <stdlib.h>
#include "lexer/scanner.h"
#include <wchar.h>
#include "lexer/pp.h"
#include <locale.h>

#define MIN_UNIC_BOUND 1570
#define MAX_UNIC_BOUND 1740

#define WCHAR_TO_ASCI(c) (c < 256)? (long)c: c


long hash_wchar(wchar_t c)
{
    return c;
}

int main()
{
    FileLine *start = scan_file("/home/ahmad/Desktop/input2.txt");
    FileLine *current = start->next_line;

    while(current != NULL)
    {


        wprintf(L"--%ls--|--%s--\n", current->line_content, preprocess_line(current));
        current = current->next_line;
    }

    return EXIT_SUCCESS;
}

//int main()
//{
//    char *locale = setlocale(LC_ALL, "");
//    wchar_t *str = L"این یک فارسی است";
//    wchar_t *str2 = (wchar_t *)malloc(20 * sizeof(wchar_t));
//    wcsncpy(str2, str, wcslen(str));
////    wprintf(L"%ls -- %d\n", str, wcslen(str));
////    wprintf(L"%ls -- %d\n", str2, wcslen(str2));
//    FileLine * start = test();
////    if (start == NULL) wprintf(L"%ls ------------------- %d\n", str, wcslen(str));
//    FileLine *current = start->next_line;
//
//    while(current != NULL)
//    {
//        wprintf(L"%ls\n", current->line_content);
//        current = current->next_line;
//    }
//    return 0;
//}