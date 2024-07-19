#include <assert.h>
#include <stdlib.h>
#include "demo.h"

// run with: gcc -Wall --std=c99 -pedantic demo.c test.c  -Wimplicit-fallthrough  -o demo && ./demo


typedef struct llist_entry {
    llist_item_type item;
    struct llist_entry *prev;
} llist_entry;

struct llist_type {
    struct llist_entry *head;
};


llist_type *llist_new(void)
{
    llist_type *list = malloc(sizeof(llist_type));
    list->head = NULL;
    return list;
}

int llist_push(llist_type *list, llist_item_type item)
{
    llist_entry *new_entry = malloc(sizeof(llist_entry));
    if (new_entry == NULL) {
        return -1;
    }
    // new_entry is a pointer, so assigning must be with ->, not .
    new_entry->item = item;
    new_entry->prev = list->head;
    // list->head must be set to the latest object in the llist
    list->head = new_entry;
    return 0;
}

int llist_pop(llist_type *list, llist_item_type *result)
{
    // end of the list, no more entries to pop
    if (list->head == NULL) {
        *result = 0;
        return -1;
    }
    *result = list->head->item;
    llist_entry *current_entry = list->head;
    list->head = list->head->prev;
    free(current_entry);
    return 0;
}

void llist_free(llist_type *list)
{
    llist_item_type ignored_result;
    while (list->head) {
        int result = llist_pop(list, &ignored_result);
        assert(result == 0);
    }
    free(list);
}