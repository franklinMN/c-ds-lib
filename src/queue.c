#include "ds/queue.h"
#include <stdlib.h>

Queue* queue_create(ds_free_fn free_fn){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue) return NULL;
    queue->head = NULL;
    queue->tail = NULL;
    queue->free_fn = free_fn;
    return queue;
}

int queue_enqueue(Queue* queue, void* data){
    if(!queue) return -1;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node) return -1;
    node->data = data;
    node->next = NULL;
    
    if(!queue->tail){
        queue->head = node;
        queue->tail = node;
        return 0;
    }

    queue->tail->next = node;
    queue->tail = node;
    return 0;
}

int queue_dequeue(Queue* queue, void** out){
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
        if(queue->free_fn && curr->data){
            queue->free_fn(curr->data);
        }
        free(curr);
        curr = next;
    }
    free(queue);
}