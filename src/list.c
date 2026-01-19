
#include <stdlib.h>
#include "ds/list.h"

List* list_create(void){
    List* list = (List*)malloc(sizeof(List));
    if(!list) return NULL;
    list->head = NULL;
    return list;
}

void list_push_front(List* list, int value){
    if(!list) return;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node) return;
    node->data = value;
    node->next = list->head;
    list->head = node;
}

void list_push_back(List* list, int value){
    if(!list) return;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node) return;
    node->data = value;

    if(!list->head){
        list->head = node;
        return;
    }

    ListNode* curr = list->head;
    while(curr->next) curr = curr->next;

    curr->next = node;
}

void list_pop_back(List* list, int* out){
    // list is not created or no elements in the list
    if(!list || !list->head) return;

    // if only one node in the list
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        return;
    }

    // if more than one elements
    ListNode* curr = list->head;
    while(curr->next->next) curr = curr->next;

    // write and then delete the last node
    if(out) *out = curr->next->data;
    free(curr->next);
    curr->next = NULL;
}

int list_pop_front(List* list, int* out){
    if(!list || !list->head) return -1;

    ListNode* temp = list->head;
    if(out) *out = temp->data;
    
    list->head = temp->next;
    free(temp);
    return 0;
}

void list_destroy(List* list){
    if(!list) return;
    ListNode* curr = list->head;
    while(curr){
        ListNode* next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}