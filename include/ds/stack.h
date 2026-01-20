#ifndef DS_STACK_H
#define DS_STACK_H

#include "ds/list.h"

typedef struct Stack {
    List* list;
}Stack;

/* creation / destruction */
Stack* stack_create(ds_free_fn free_fn);
void stack_destroy(Stack* stack);

/* operations */
int stack_push(Stack* stack, void* data);
int stack_pop(Stack* stack, void** out);
int stack_is_empty(const Stack* stack);

# endif /* DS_STACK_H */