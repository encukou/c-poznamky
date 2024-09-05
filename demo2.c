#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "demo.h"

// run with: gcc -Wall --std=c99 -pedantic demo2.c test.c  -Wimplicit-fallthrough  -o demo && ./demo


typedef struct llist_entry {
    llist_item_type item;
    struct llist_entry *prev;
    struct llist_entry *next;
} llist_entry;

struct llist_type {
    struct llist_entry base;
    ssize_t count;
};


llist_type *llist_new(void)
{
    llist_type *list = malloc(sizeof(llist_type));
    if (list == NULL) {
        return NULL;
    }
    list->base.item = -1;
    list->base.prev = &(list->base);
    list->base.next = &(list->base);
    list->count = 0;
    return list;
}

int llist_push(llist_type *list, llist_item_type item)
{
    llist_entry *new_entry = malloc(sizeof(llist_entry));
    if (new_entry == NULL) {
        return -1;
    }
    new_entry->item = item;
    new_entry->prev = list->base.prev;
    new_entry->next = &(list->base);

    list->base.prev->next = new_entry;
    list->base.prev = new_entry;

    list->count++;
    return 0;
}

int llist_pop(llist_type *list, llist_item_type *result)
{
    llist_entry *last_entry = list->base.prev;

    if (last_entry == &(list->base)) {
        // nothing to pop
        *result = 0;
        return -1;
    }

    *result = last_entry->item;
    list->base.prev = last_entry->prev;
    list->base.prev->next = &(list->base);
    free(last_entry);
    list->count--;
    return 0;
}

void llist_free(llist_type *list)
{
    llist_item_type ignored_result;
    while (list->base.prev != &(list->base)) {
        int result = llist_pop(list, &ignored_result);
        assert(result == 0);
    }
    free(list);
}

ssize_t llist_count(llist_type *list)
{
    return list->count;
}

// int llist_get(llist_type *list, ssize_t n, llist_item_type *result) {
//     for (llist_entry *current = list->base.next; current; current = current->prev) {
//         if (n-- == 0) {
//             *result = current->item;
//             return 0;
//         }
//     }
//     // we iterated till the end and haven't found the nth element
//     *result = 0;
//     return -1;
// }