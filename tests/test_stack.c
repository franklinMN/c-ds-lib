#include <assert.h>
#include "ds/stack.h"

int main(void){
    Stack* stack = stack_create();
    assert(stack != NULL);
    assert(stack_is_empty(stack));

    int value;
    stack_push(stack, 1);
    stack_push(stack, 2);

    assert(stack_pop(stack, &value) == 0);
    assert(value == 2);

    assert(stack_pop(stack, &value) == 0);
    assert(value == 1);

    assert(stack_pop(stack, &value) == -1);

    stack_destroy(stack);

    return 0;
}