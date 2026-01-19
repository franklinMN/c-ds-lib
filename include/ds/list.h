#ifndef DS_LIST_H
#define DS_LIST_H

#include <stddef.h> // size_t

typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;

typedef struct List{
    ListNode* head;
}List;


List* list_create(void);
void list_push_front(List* list, int value);
void list_push_back(List* list, int value);
// returns 0 on success, -1 if list is empty
int list_pop_front(List* list, int* out);
void list_destroy(List* list);

#endif /* DS_LIST_H */