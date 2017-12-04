# About the utility package

This package contains the utility such as data structures needed in Razpiler to be implemented:

## LLStack

LLStack is a stack implementation with linked list.

~~~c
    LLStack stack;
    llstack_init(&stack);
    llstack_push(stack, f(12));
    llstack_push(stack, f(13));
    llstack_push(stack, f(15));
    llstack_push(stack, f(18));
    llstack_push(stack, f(1));
    llstack_push(stack, f(-1));

    do
    {

        printf("%d\n", (*(int *)llstack_top(stack)));
        llstack_pop(stack);
    }
    while (!llstack_is_empty(stack));
~~~

## LLList

LLList is a linked list implementation of unlimited list

~~~c
    LLList list;
    lllist_init(&list);

    lllist_push_back(list, f(14));
    lllist_push_back(list, f(15));
    lllist_push_back(list, f(16));
    lllist_push_back(list, f(17));
    lllist_push_back(list, f(19));

    printf("%d\n", (*(int *)lllist_get_current(list)));
    lllist_step_backward(list);
    LLListNode c = lllist_get_current_p(list);
    printf("%d\n", (*(int *)lllist_get_current(list)));
    lllist_step_backward(list);
    printf("%d\n", (*(int *)lllist_get_current(list)));
    lllist_step_backward(list);
    lllist_set_current_p(list, c);
    printf("%d\n", (*(int *)lllist_get_current(list)));
~~~