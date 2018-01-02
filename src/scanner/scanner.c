#include "scanner.h"
#include "pp.h"
#include <locale.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>
#include "../stdout/stdout.h"

#define IS_NEWLINE(c) ((c) == L'\n')? true:false                        // Macro for checking if the char is newLine char
#define BUFFER_ALLOC(size) (wchar_t *)malloc(size * sizeof(wchar_t))    // Macro for allocation of memory of buffer
#define LINE_ALLOC() (FileLine *)malloc(sizeof(FileLine))               // Macro for allocation of memory of buffer
#define INIT_BUFFER_SIZE 250


void enlarge_buffer(wchar_t **, size_t *);                               //  Make the buffer of reading line larger
void new_line(FileLine **, wchar_t *, size_t, long long, FILE *);        //  Add new node to lines linked list
FileLine *separate_lines(FILE *);                                        //  Read the file and separate it to lines

LLList lexeme_list;

FileLine *scan_file(char *file_path)
{
    FILE *file;
    file = fopen(file_path, "r");

    lllist_init(&lexeme_list);

    if (file == NULL)   // If any error occurred in opening the file
    {
        std_out(ERROR_TYPE_CRITICAL, ERROR_FILE_NOT_FOUND);
        return NULL;
    }

    FileLine *start = separate_lines(file);
    FileLine *current = start->next_line;

    while(current != NULL)
    {
//        wprintf(L"%ls       ", current->line_content);
        char *str = preprocess_line(current);
//        wprintf(L"00%s00\n", str);
//        start_lex(str, current);
//        func(str, current);
//        wprintf(L"--%ls--|--%s--\n", current->line_content, str);
//        func(str, NULL);
        current = current->next_line;
    }
    return start;
}


FileLine *separate_lines(FILE *file)
{
    // Setting the pointers of first and current node of linked list to NULL
    FileLine *start_line_pointer = (FileLine *)malloc(sizeof(FileLine));
    FileLine *current_line_pointer = start_line_pointer;

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
            buffer[buffer_used] = L'\0';
            if (wcslen(buffer) != 0)
                new_line(&current_line_pointer, buffer, buffer_used, line_num, file);
            line_num++;
            buffer_size = INIT_BUFFER_SIZE;
            free(buffer);
            buffer = BUFFER_ALLOC(buffer_size);
            buffer_used = 0;
        }
        else
        {
            buffer[buffer_used++] = c;
            if (buffer_used == buffer_size) enlarge_buffer(&buffer, &buffer_size); // Largest buffer should be allocated
        }
    }

    if (wcslen(buffer) != 0) new_line(&current_line_pointer, buffer, buffer_used, line_num, file);
    free(buffer);

    fclose(file);

    return start_line_pointer;
}

void enlarge_buffer(wchar_t **buffer, size_t *buffer_size)
{
    wchar_t *new_buffer = BUFFER_ALLOC((*buffer_size) *= 2);
    memcpy(new_buffer, (*buffer), (*buffer_size) / 2);
    new_buffer[(*buffer_size) / 2] = L'\0';
    free((*buffer));
    (*buffer) = new_buffer;
}

void new_line(FileLine **current_line_pointer,wchar_t *line_content, size_t line_size, long long line_num, FILE * file)
{
    FileLine *node = LINE_ALLOC();
    node->line_content = (wchar_t *)malloc((line_size + 1) * sizeof(wchar_t));
    wcsncpy(node->line_content, line_content, line_size + 1);
    node->line_num = line_num;
    node->file = file;
    node->next_line = NULL;

    (*current_line_pointer)->next_line = node;
    (*current_line_pointer) = node;
}