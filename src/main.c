#include <stdlib.h>
#include "lexer/scanner.h"
#include <wchar.h>
#include "lexer/pp.h"
#include <locale.h>

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