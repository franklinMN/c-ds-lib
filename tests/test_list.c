#include <assert.h>
#include "ds/list.h"

int main(void){
    List* list = list_create();
    assert(list != NULL);

    int value;
    assert(list_pop_front(list, &value) == -1);

    list_push_front(list, 10);
    list_push_front(list, 20);

    assert(list_pop_front(list, &value) == 0);
    assert(value == 20);

    assert(list_pop_front(list, &value) == 0);
    assert(value == 10);

    assert(list_pop_front(list, &value) == -1);

    list_destroy(list);
    return 0;
}