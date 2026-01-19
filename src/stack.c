#include "ds/stack.h"
#include <stdlib.h>

Stack* stack_create(void){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack) return NULL;
    stack->list = list_create();
    if(!stack->list){
        free(stack);
        return NULL;
    }
    return stack;
}

void stack_push(Stack* stack, int value){
    if(!stack) return;
    list_push_front(stack->list, value);
}

int stack_pop(Stack* stack, int* out){
    if(!stack) return -1;
    return list_pop_front(stack->list, out);
}

int stack_is_empty(const Stack* stack){
    return !stack || !stack->list || !stack->list->head;
}
void stack_destroy(Stack* stack){
    if(!stack) return;
    list_destroy(stack->list);
    free(stack);
}