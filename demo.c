#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "demo.h"

// run with: gcc -Wall --std=c99 -pedantic demo.c test.c  -Wimplicit-fallthrough  -o demo && ./demo


typedef struct llist_entry {
    llist_item_type item;
    struct llist_entry *prev;
    struct llist_entry *next;
} llist_entry;

struct llist_type {
    struct llist_entry *head;
    struct llist_entry *tail;
    ssize_t count;
};


llist_type *llist_new(void)
{
    llist_type *list = malloc(sizeof(llist_type));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
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
    new_entry->prev = list->head; // `NULL` if adding the first element
    new_entry->next = NULL;

    if (list->head == NULL) {
        list->tail = new_entry; // tail is set only with the 1st entry
    } else {
        // the previous next was NULL, update it to the current entry
        new_entry->prev->next = new_entry;
    }
    // list->head must be set to the latest object in the llist
    list->head = new_entry;
    list->count++;
    llist_check(list);
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
    // if I popped the last element, there's no next at all
    // LLM-aided (dereference list->head after reassigning the value)
    if (list->head != NULL) {
        // update the current last element of the list - there's no next after it
        list->head->next = NULL;
    }
    free(current_entry);
    list->count--;
    llist_check(list);
    return 0;
}

int llist_popleft(llist_type *list, llist_item_type *result)
{
    // end of the list, no more entries to pop
    if (list->tail == NULL) {
        *result = 0;
        return -1;
    }

    *result = list->tail->item;
    llist_entry *current_entry = list->tail;
    list->tail = list->tail->next;
    // if I popped the last element, there's no next at all
    if (list->tail != NULL) {
        // update the current last element of the list - there's no next after it
        list->tail->prev = NULL;
    }
    free(current_entry);
    list->count--;
    llist_check(list);
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
    if (list->head == NULL) {
        return -1;
    }
    // from head to tail
    llist_entry *current = list->head;
    while (current) {
        printf("%d\n", current->item);
        current = current->prev;
    }
    printf("and now the other way around:\n");
    // from tail to head
    current = list->tail;
    while (current) {
        printf("%d\n", current->item);
        current = current->next;
    }

    return 0;
}

void llist_check(llist_type *list) {
    if (list->head == NULL) {
        return;
    }
    // from head to tail
    ssize_t cnt_from_head = 0;
    llist_entry *current = list->head;
    while (current) {
        if (current->next != NULL) {
            assert(current->next->prev == current);
        }
        current = current->prev;
        cnt_from_head++;
    }
    // the other way around
    ssize_t cnt_from_tail = 0;
    current = list->tail;
    while (current) {
        if (current->prev != NULL) {
            assert(current->prev->next == current);
        }
        current = current->next;
        cnt_from_tail++;
    }
    assert(cnt_from_head == cnt_from_tail);
    assert(cnt_from_head == list->count);
}

ssize_t llist_count(llist_type *list)
{
    return list->count;
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

ssize_t llist_remove_first_n(llist_type *list, ssize_t n)
{
    llist_item_type ignored_result;

    for (ssize_t n_popped_items = 0; n_popped_items < n;n_popped_items++) {
        llist_check(list);
        if (list->head == NULL) {
            return n_popped_items;
        }
        if (llist_pop(list, &ignored_result) == -1) {
            return -1;
        }
    }
    return n;
}

int llist_remove(llist_type *list, ssize_t n, llist_item_type *result)
{
    if (n == 0) {
        return llist_pop(list, result);
    }
    if (n == (list->count)-1) {
        return llist_popleft(list, result);
    }

    for (llist_entry *current = list->head; current; current = current->prev) {
        // stopping one item before the one I want to remove
        if (n-- == 1) {
            if (current->prev == NULL) {
                *result = 0;
                return -1;
            }
            llist_entry *entry_to_delete = current->prev;
            *result = entry_to_delete->item;
            current->prev = entry_to_delete->prev;
            entry_to_delete->prev->next = current;
            free(entry_to_delete);
            list->count--;
            llist_check(list);
            return 0;
        }
    }
    *result = 0;
    return -1;

// *ptr_to_update points to the current entry
// ptr_to_update is the pointer which we need to update if we remove that entry

    // for (
    //     llist_entry **ptr_to_update = &list->head;
    //      *ptr_to_update != (llist_entry *)NULL;
    //      ptr_to_update = &((*ptr_to_update)->prev)
    // ) {
    //     if (n-- == 0) {
    //         llist_entry *entry_to_delete = *ptr_to_update;
    //         *result = entry_to_delete->item;
            
    //         // sth along the lines? segfaults :(
    //         if (entry_to_delete->prev != NULL) {
    //             entry_to_delete->prev->next = entry_to_delete->next;
    //         }
    //         if (entry_to_delete->next != NULL) {
    //             entry_to_delete->next->prev = entry_to_delete->prev;
    //         }

    //         *ptr_to_update = entry_to_delete->prev;
    //         free(entry_to_delete);
    //         list->count--;
    //         llist_check(list);
    //         return 0;
    //     }
    // }

}
