
#include <stdlib.h>
#include "ds/list.h"

List* list_create(ds_free_fn free_fn){
    List* list = (List*)malloc(sizeof(List));
    if(!list) return NULL;
    list->head = NULL;
    list->free_fn = free_fn;
    return list;
}

int list_push_front(List* list, void* data){
    if(!list) return -1;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node) return -1;
    node->data = data;
    node->next = list->head;
    list->head = node;
    return 0;
}

int list_push_back(List* list, void* data){
    if(!list) return -1;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node) return -1;
    node->data = data;
    node->next = NULL;

    if(!list->head){
        list->head = node;
        return 0;
    }

    ListNode* curr = list->head;
    while(curr->next) curr = curr->next;
    curr->next = node;
    return 0;
}

int list_pop_front(List* list, void** out){
    if(!list || !list->head) return -1;

    ListNode* temp = list->head;
    if(out) *out = temp->data;
    
    list->head = temp->next;
    free(temp);
    return 0;
}

int list_is_empty(const List* list){
    return (!list || !list->head);
}

void list_destroy(List* list){
    if(!list) return;
    ListNode* curr = list->head;
    while(curr){
        ListNode* next = curr->next;
        if(list->free_fn && curr->data){
            list->free_fn(curr->data);
        }
        free(curr);
        curr = next;
    }
    free(list);
}