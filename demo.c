// gcc -Wall -std=c99 -pedantic demo.c test.c -o demo && ./demo

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "demo.h"

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
    new_entry->item = item;
    new_entry->prev = list->head;
    list->head = new_entry;
    return 0;
}

int llist_pop(llist_type *list, llist_item_type *result)
{
    if (list->head == NULL) {
        *result = 0;
        return -1;
    }
    *result = list->head->item;
    llist_entry *prev_head = list->head;
    list->head = list->head->prev;
    free(prev_head);
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

int llist_dump(llist_type *list)
{
    printf("Contents of list %p:\n", (void*)list);
    /*
    llist_entry *current = list->head;
    while (current) {
        printf("- %d\n", current->item);
        current = current->prev;
    }
    */
    for (llist_entry *current = list->head; current; current = current->prev) {
        printf("- %d\n", current->item);
    }
    printf("End of list %p.\n", (void*)list);
    return 0;
}

ssize_t llist_count(llist_type *list)
{
    ssize_t cnt = 0;
    for (llist_entry *current = list->head; current; current = current->prev) {
        cnt++;
    }
    return cnt;
}

int llist_get(llist_type *list, ssize_t n, llist_item_type *result) {
    for (llist_entry *current = list->head; current; current = current->prev) {
        if (n-- == 0) {
            *result = current->item;
            return 0;
        }
    }
    // we iterated till the end and haven't found the nth element
    *result = 0;
    return -1;
}
