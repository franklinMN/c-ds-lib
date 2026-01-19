#include <assert.h>
#include "ds/queue.h"

int main(void){
    Queue* queue = queue_create();
    assert(queue != NULL);

    int value;
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);

    assert(queue_dequeue(queue, &value) == 0);
    assert(value == 1);

    assert(queue_dequeue(queue, &value) == 0);
    assert(value == 2);

    assert(queue_dequeue(queue, &value) == -1);

    queue_destroy(queue);
    return 0;
}