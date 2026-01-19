#ifndef DS_LIST_H
#define DS_LIST_H

#include <stddef.h> // size_t

// node structure
typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;

// list structure
typedef struct List{
    ListNode* head;
}List;

// create an empty list
List* list_create(void);

// insert at front
void list_push_front(List* list, int value);

// insert at back
void list_push_back(List* list, int value);

// remove front node
void list_pop_back(List* list, int* out);

// remove front node
// returns 0 on success, -1 if list is empty
int list_pop_front(List* list, int* out);

// free all nodes and the list
void list_destroy(List* list);

#endif // DS_LIST_H