#include "ds/queue.h"
#include <stdlib.h>

Queue* queue_create(void){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue) return NULL;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void queue_enqueue(Queue* queue, int value){
    if(!queue) return;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node) return;
    node->data = value;
    node->next = NULL;
    
    if(!queue->tail){
        queue->head = node;
        queue->tail = node;
        return;
    }

    queue->tail->next = node;
    queue->tail = node;
}

int queue_dequeue(Queue* queue, int* out){
    if(!queue || !queue->head) return -1;

    ListNode* temp = queue->head;
    if(out) *out = temp->data;

    queue->head = temp->next;
    if(!queue->head) queue->tail = NULL;

    free(temp);
    return 0;
    
}

int queue_is_empty(const Queue* queue){
    return !queue || !queue->head;
}

void queue_destroy(Queue* queue){
    if(!queue) return;
    ListNode* curr = queue->head;
    while(curr){
        ListNode* next = curr->next;
        free(curr);
        curr = next;
    }
    free(queue);
}