#include <assert.h>
#include <stdlib.h>
#include "ds/list.h"

/* helper to allocate int */
static int* make_int(int v){
    int* p = (int*)malloc(sizeof(int));
    assert(p != NULL);
    *p = v;
    return p;
}

int main(void){
    /* list owns data (free_fn = free) */
    List* list = list_create(free);
    assert(list != NULL);
    assert(list_is_empty(list));

    int* a = make_int(10);
    int* b = make_int(20);

    assert(list_push_front(list, a) == 0);
    assert(list_push_front(list, b) == 0);

    void* out = NULL;

    assert(list_pop_front(list, &out) == 0);
    assert(*(int*)out == 20);
    free(out);

    assert(list_pop_front(list, &out) == 0);
    assert(*(int*)out == 10);
    free(out);

    assert(list_pop_front(list, &out) == -1);

    /* remaining nodes (none) are freed safely */
    list_destroy(list);
}