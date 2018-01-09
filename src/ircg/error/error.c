#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "../../stdout/stdout.h"

void error_id_not_declared(char *id)
{
    printf("error : id not found\n");
    exit(-1);
}

void main_not_found()
{
    std_out(ERROR_TYPE_CRITICAL, ERROR_MAIN_NOT_FOUND);
}
