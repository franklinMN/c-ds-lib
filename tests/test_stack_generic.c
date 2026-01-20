#include <assert.h>
#include <stdlib.h>
#include "ds/stack.h"

/* helper to allocate int */
static int* make_int(int v){
    int* p = (int*)malloc(sizeof(int));
    assert(p != NULL);
    *p = v;
    return p;
}

int main(void){
    Stack* stack = stack_create(free);
    assert(stack != NULL);
    assert(stack_is_empty(stack));

    int* a = make_int(1);
    int *b = make_int(2);

    assert(stack_push(stack, a) == 0);
    assert(stack_push(stack, b) == 0);
    assert(!stack_is_empty(stack));

    void* out = NULL;

    assert(stack_pop(stack, &out) == 0);
    assert(*(int*)out == 2);
    free(out);

    assert(stack_pop(stack, &out) == 0);
    assert(*(int*)out == 1);
    free(out);

    assert(stack_pop(stack, &out) == -1);
    assert(stack_is_empty(stack));

    stack_destroy(stack);
    return 0;
}