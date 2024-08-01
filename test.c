#include <assert.h>
#include "demo.h"

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
    result = llist_push(list, 7);
    result = llist_count(list);
    assert(result == 1);
    result = llist_push(list, 8);
    result = llist_count(list);
    assert(result == 2);
    result = llist_push(list, 12);
    result = llist_count(list);
    assert(result == 3);
    llist_item_type nth;
    result = llist_get(list, 0, &nth);
    assert(result == 0);
    assert(nth == 12);
    result = llist_get(list, 1, &nth);
    assert(result == 0);
    assert(nth == 8);
    result = llist_get(list, 2, &nth);
    assert(result == 0);
    assert(nth == 7);
    result = llist_get(list, 5, &nth);
    assert(result == -1);
    assert(nth == 0);
    result = llist_pop(list, &entry);
    result = llist_count(list);
    assert(result == 2);
    result = llist_dump(list);
    assert(result == 0);
    llist_free(list);

    list = llist_new();
    result = llist_count(list);
    assert(result == 0);
    result = llist_dump(list);
    assert(result == -1);
    llist_free(list);

    list = llist_new();
    assert(list);
    result = llist_push(list, 7);
    result = llist_push(list, 8);
    result = llist_push(list, 12);
    result = llist_push(list, 20);
    result = llist_count(list);
    assert(result == 4);
    result = llist_remove_first_n(list, 1);
    assert(result == 0);
    result = llist_count(list);
    assert(result == 3);
    result = llist_remove_first_n(list, 2);
    assert(result == 0);
    result = llist_count(list);
    assert(result == 1);
    result = llist_remove_first_n(list, 1);
    assert(result == 0);
    result = llist_count(list);
    assert(result == 0);
    result = llist_remove_first_n(list, 3);
    assert(result == -1);
    result = llist_push(list, 7);
    result = llist_push(list, 8);
    result = llist_push(list, 12);
    result = llist_push(list, 20);
    result = llist_push(list, 25);
    result = llist_count(list);
    assert(result == 5);
    result = llist_remove(list, 3, &entry);
    assert(result == 0);
    assert(entry == 8);
    result = llist_count(list);
    assert(result == 4);
    result = llist_remove(list, 4, &entry);
    assert(result == -1);
    assert(entry == 0);
    result = llist_count(list);
    assert(result == 4);
    result = llist_remove(list, 0, &entry);
    assert(result == 0);
    assert(entry == 25);
    result = llist_count(list);
    assert(result == 3);
    result = llist_remove(list, 0, &entry);
    assert(result == 0);
    assert(entry == 20);
    result = llist_count(list);
    assert(result == 2);
    result = llist_remove(list, 1, &entry);
    assert(result == 0);
    assert(entry == 7);
    result = llist_count(list);
    assert(result == 1);
    result = llist_remove(list, 1, &entry);
    assert(result == -1);
    assert(entry == 0);
    result = llist_count(list);
    assert(result == 1);
    result = llist_remove(list, 0, &entry);
    assert(result == 0);
    assert(entry == 12);
    result = llist_count(list);
    assert(result == 0);
    result = llist_remove(list, 24, &entry);
    assert(result == -1);
    assert(entry == 0);
    result = llist_count(list);
    assert(result == 0);
    llist_free(list);

}
