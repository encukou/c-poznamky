#include <assert.h>
#include "demo.h"
#include <stdio.h>

int main() {
    llist_type *list = llist_new();
    assert(list);

    llist_item_type entry;
    int result = llist_pop(list, &entry);
    assert(result == -1);
    assert(entry == 0);

    result = llist_push(list, 7);
    assert(result == 0);

    result = llist_pop(list, &entry);
    assert(result == 0);
    assert(entry == 7);

    result = llist_pop(list, &entry);
    assert(result == -1);
    assert(entry == 0);

    result = llist_push(list, 7);
    assert(result == 0);
    result = llist_push(list, 8);
    assert(result == 0);
    result = llist_push(list, 12);
    assert(result == 0);

    result = llist_pop(list, &entry);
    assert(result == 0);
    assert(entry == 12);
    result = llist_pop(list, &entry);
    assert(result == 0);
    assert(entry == 8);
    result = llist_pop(list, &entry);
    assert(result == 0);
    assert(entry == 7);

    result = llist_pop(list, &entry);
    assert(result == -1);
    assert(entry == 0);

    llist_free(list);

    list = llist_new();
    assert(list);
    llist_dump(list);

    llist_push(list, 7);
    llist_push(list, 8);
    llist_push(list, 12);

    llist_dump(list);

    llist_free(list);

    list = llist_new();
    assert(list);
    assert(llist_push(list, 7) == 0);
    assert(llist_push(list, 8) == 0);
    assert(llist_push(list, 12) == 0);
    llist_dump(list);
    assert(llist_remove_first_n(list, 1) == 1);
    assert(llist_count(list) == 2);
    llist_dump(list);
    assert(llist_remove_first_n(list, 10) == 2);
    assert(llist_count(list) == 0);
    llist_dump(list);
    assert(llist_remove_first_n(list, 1) == 0);
    assert(llist_count(list) == 0);
    llist_free(list);
}
