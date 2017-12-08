#include "exp.h"

#include <stdlib.h>

#if defined(unix) || defined(__unix__) || defined(__unix)
#include <stdlib.h>     // Should be activated in linux
#else
#include <stdlib.h>     // Should be activated in MacOSX
#endif

void exp_init(Expression *expression)
{
    (*expression) = malloc(sizeof(ExpressionType));
    lllist_init(&((*expression)->false_list));
    lllist_init(&((*expression)->true_list));
}

void exp_set_place(Expression exp)
{

}
