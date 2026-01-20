#ifndef DS_LIST_H
#define DS_LIST_H

#include <stddef.h> /* size_t */

/* user-provided free function (optional) */
typedef void (*ds_free_fn)(void*);

typedef struct ListNode{
    void* data;
    struct ListNode* next;
}ListNode;

typedef struct List{
    ListNode* head;
    ds_free_fn free_fn; /* may be NULL */
}List;

/* creation / destruction */
List* list_create(ds_free_fn free_fn);
void list_destroy(List* list);

/* insertion */
int list_push_front(List* list, void* data);
int list_push_back(List* list, void* data);

/* removal */
/* returns 0 on success, -1 if list is empty */
int list_pop_front(List* list, void** out);

/* utilities */
int list_is_empty(const List* list);

#endif /* DS_LIST_H */