#include "scanner.h"
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>
#include <memory.h>

#define IS_NEWLINE(c) ((c) == L'\n')? true:false            // Macro for checking if the char is newLine char
#define BUFFER_ALLOC(size) (wchar_t *)malloc(size * sizeof(wchar_t))    // Macro for allocation of memory of buffer
#define LINE_ALLOC() (FileLine *)malloc(sizeof(FileLine))    // Macro for allocation of memory of buffer
#define INIT_BUFFER_SIZE 50


void enlarge_buffer(wchar_t **, size_t *);      //  Make the buffer of reading line larger
void new_line(wchar_t *, size_t, long long, FILE *);    //  Add new node to lines linked list
void separate_lines(FILE *);                    //  Read the file and separate it to lines



FileLine *start_line_pointer;       // Pointer to first node of linked list of file's lines
FileLine *current_line_pointer;     // Pointer to first node of linked list of file's lines


int scan_file(char *file_path)
{
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

    wchar_t c;       // Type for reading the characters from the file
    size_t buffer_size = INIT_BUFFER_SIZE, buffer_used = 0;
    wchar_t *buffer;                        // Buffer for reading the chars from the file

    long long line_num = 1;

    buffer = BUFFER_ALLOC(buffer_size);

    while ((c = fgetwc(file)) != WEOF)
    {
        if (IS_NEWLINE(c))
        {
            new_line(buffer, buffer_used, line_num, file);
            buffer_size = INIT_BUFFER_SIZE;
            free(buffer);
            buffer = BUFFER_ALLOC(buffer_size);
        }
        else
        {
            buffer[buffer_used++] = c;
            if (buffer_used == buffer_size) enlarge_buffer(&buffer, &buffer_size); // Largest buffer should be allocated
            putwchar(c);
        }
    }

    fclose(file);
}

void enlarge_buffer(wchar_t **buffer, size_t *buffer_size)
{
    wchar_t *new_buffer = BUFFER_ALLOC((*buffer_size) *= 2);
    memcpy(new_buffer, (*buffer), (*buffer_size) / 2);
    free((*buffer));
}

void new_line(wchar_t *line_content, size_t line_size, long long line_num, FILE * file)
{
    FileLine *node = LINE_ALLOC();
    wcsncpy(node->line_content, line_content, line_size);
    node->line_num = line_num;
    node->file = file;
    node->next_line = NULL;

    current_line_pointer->next_line = node;
}