#include <assert.h>
#include <stdlib.h>
#include "ds/queue.h"

/* helper to allocate int */
static int* make_int(int v) {
    int* p = (int*)malloc(sizeof(int));
    assert(p != NULL);
    *p = v;
    return p;
}

int main(void){
    Queue* queue = queue_create(free);
    assert(queue != NULL);
    assert(queue_is_empty(queue));

    int* a = make_int(1);
    int* b = make_int(2);

    assert(queue_enqueue(queue, a) == 0);
    assert(queue_enqueue(queue, b) == 0);

    void* out = NULL;

    assert(queue_dequeue(queue, &out) == 0);
    assert(*(int*)out == 1);
    free(out);

    assert(queue_dequeue(queue, &out) == 0);
    assert(*(int*)out == 2);
    free(out);

    assert(queue_dequeue(queue, &out) == -1);
    assert(queue_is_empty(queue));

    queue_destroy(queue);
    return 0;
}