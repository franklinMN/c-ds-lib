#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "ds/list.h"

typedef struct Queue{
    ListNode* head;
    ListNode* tail;
    ds_free_fn free_fn;
}Queue;

/* creation / destruction */
Queue* queue_create(ds_free_fn free_fn);
void queue_destroy(Queue* queue);

/* operation */
int queue_enqueue(Queue* queue, void* data);
int queue_dequeue(Queue* queue, void** out);
int queue_is_empty(const Queue* queue);

#endif /* DS_QUEUE_H */