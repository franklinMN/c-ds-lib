#ifndef DS_STACK_H
#define DS_STACK_H

#include "ds/list.h"

typedef struct Stack {
    List* list;
}Stack;

Stack* stack_create(void);
void stack_push(Stack* stack, int value);
int stack_pop(Stack* stack, int* out);
int stack_is_empty(const Stack* stack);
void stack_destroy(Stack* stack);

# endif // DS_STACK_H