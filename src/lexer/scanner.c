#include "scanner.h"
#include <malloc.h>
#include <locale.h>

/**
 * Read the file and separate it to lines
 */
void separate_lines(FILE *);

FileLine *start_line_pointer;       // Pointer to first node of linked list of file's lines
FileLine *current_line_pointer;       // Pointer to first node of linked list of file's lines

// Open the file with given path for reading and call the line separator
int scan_file(char *file_path) {
    FILE *file;
    file = fopen(file_path, "r");

    if (file == NULL)   // If any error occurred in opening the file
        return FILE_CANNOT_BE_OPEN_ERR;

    separate_lines(file);
}

void separate_lines(FILE *file)
{
    // Setting the pointers of first and current node of linked list to NULL
    start_line_pointer = (FileLine *)malloc(sizeof(FileLine));
    current_line_pointer = start_line_pointer;

    start_line_pointer->next_line = NULL;

    char *locale = setlocale(LC_ALL, "");       // Set the locale for reading the persian characters

    wint_t c;
    while ((c = fgetwc(file)) != WEOF)
    {
        putwchar(c);
    }
    fclose(file);


}

