#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "ds/list.h"

typedef struct Queue{
    ListNode* head;
    ListNode* tail;
}Queue;

Queue* queue_create(void);
void queue_enqueue(Queue* queue, int value);
int queue_dequeue(Queue* queue, int* out);
int queue_is_empty(const Queue* queue);
void queue_destroy(Queue* queue);

#endif /* DS_QUEUE_H */