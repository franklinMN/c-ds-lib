#include "ds/stack.h"
#include <stdlib.h>

Stack* stack_create(ds_free_fn free_fn){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack) return NULL;
    stack->list = list_create(free_fn);
    if(!stack->list){
        free(stack);
        return NULL;
    }
    return stack;
}

int stack_push(Stack* stack, void* data){
    if(!stack) return -1;
    list_push_front(stack->list, data);
}

int stack_pop(Stack* stack, void** out){
    if(!stack) return -1;
    return list_pop_front(stack->list, out);
}

int stack_is_empty(const Stack* stack){
    return !stack || list_is_empty(stack->list);
}
void stack_destroy(Stack* stack){
    if(!stack) return;
    list_destroy(stack->list);
    free(stack);
}