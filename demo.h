
typedef int llist_item_type;

typedef struct llist_type llist_type;

llist_type *llist_new(void);  // returns NULL on error
void llist_free(llist_type *list);

int llist_push(llist_type *list, llist_item_type item);
// returns -1 on error, 0 on success

int llist_pop(llist_type *list, llist_item_type *result);
// on error, returns -1, sets *result to zero
// on success, returns 0 and sets *result
