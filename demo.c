#include "demo.h"
#include <stdlib.h>

struct llist_entry {
    llist_item_type item;
    struct llist_entry *prev;
};

struct llist_type {
    struct llist_entry *head;
};


llist_type *llist_new(void) {
    llist_type *list = malloc(sizeof(llist_type));
    return list;
}

int llist_push(llist_type *list, list_item_type entry)
{
    llist
}