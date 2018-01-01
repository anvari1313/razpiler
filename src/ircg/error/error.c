#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void error_id_not_declared(char *id)
{
    printf("error : id not found\n");
    exit(-1);
}
