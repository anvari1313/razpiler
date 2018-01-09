#include "stdout.h"
#include <stdio.h>
#include <stdlib.h>

void std_out(const unsigned char type, const unsigned char error)
{
    switch (error)
    {
        case ERROR_FILE_NOT_FOUND:
            printf("File not found\n");
            break;
        case ERROR_MAIN_NOT_FOUND:
            printf("starting point not found\n");
            break;
    }

    switch (type)
    {
        case ERROR_TYPE_CRITICAL:
            exit(-1);
        default:
            break;
    }
}
