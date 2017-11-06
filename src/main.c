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


//    char *locale = setlocale(LC_ALL, "");       // Set the locale for reading the persian characters
//    wchar_t t[100];
//    wchar_t a[100];
//    wcsncpy(a, L"اینجا", 5);
//    wcsncpy(t, a, 5);
////    for (int i = 0; i < wcslen(a); ++i) {
//
//    if (wcslen(a) != wcslen(t)) {
//        printf("%d %d", wcslen(a), wcslen(t));
////        for (int i = 0; i < 5; ++i) {
////            putwchar(t[i]);
////        }
//        return -1;
//    }


    FileLine *start = scan_file("/Users/invisible/Desktop/raz.txt");
    FileLine *current = start->next_line;
    int min = 1750;
    while(current != NULL)
    {

        if (min > current->line_content[0] && current->line_content[0] != 0) min = current->line_content[0];

        if (min == 0)
            wprintf(L"--%ls--\n", current->line_content);
        else
            wprintf(L"%ls - %ld - %c\n", current->line_content, hash_wchar(current->line_content[0]), map_to_english(current->line_content[0]));
        current = current->next_line;
    }

    wprintf(L"%d\n", min);
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