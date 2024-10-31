#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "word.h"

typedef word_hash_type dict_hash_type;

const char SINGLE_KEY[] = "helena";
const char DUMMY_KEY[] = "radius";

const size_t INITIAL_SIZE = 8;

typedef struct dict_entry {
    dict_key key;
    dict_value value;
    struct dict_entry *next;
} dict_entry;

struct dict {
    dict_entry **contents;
    size_t contents_size;
    size_t num_entries;

    // delete this:
    dict_value count; // value for SINGLE_KEY
};
struct dict_iterator {
    int position;
    dict_key current_key;
};

dict *dict_alloc(void) {
    dict *result = malloc(sizeof(dict));
    if (result == NULL) {
        return NULL;
    }
    result->count = 0;

    result->contents_size = INITIAL_SIZE;
    result->num_entries = 0;
    result->contents = malloc(sizeof(dict_entry *) * INITIAL_SIZE);
    if (result->contents == NULL) {
        free(result);
        return NULL;
    }

    return result;
}

void dict_free(dict *d) {
    for (size_t i = 0; i < d->contents_size; i++) {
        dict_entry **pointer_to_current_entry = &(d->contents[i]);
        while (*pointer_to_current_entry) {
            dict_entry *current_entry = *pointer_to_current_entry;
            pointer_to_current_entry = &(current_entry->next);
            word_free(current_entry->key);
            free(current_entry);
        }
    }
    free(d->contents);
    free(d);
}

int dict_set(dict *d, dict_key key, dict_value value) {
    dict_hash_type hash = word_hash(key);
    if (hash == -1) {
        word_free(key);
        return -1;
    }
    size_t bucket = hash % d->contents_size;

    dict_entry **pointer_to_current_entry = &(d->contents[bucket]);
    while (*pointer_to_current_entry) {
        dict_entry *current_entry = *pointer_to_current_entry;
        int result = word_equal(current_entry->key, key);
        if (result == -1) {
            word_free(key);
            return -1;
        }
        else if (result == 1) {
            current_entry->value = value;
            word_free(key);
            return 0;
        }
        pointer_to_current_entry = &(current_entry->next);
    }

    // if we get here, we need to add a new entry
    dict_entry *new_entry = malloc(sizeof(dict_entry));
    if (new_entry == NULL) {
        word_free(key);
        return -1;
    }
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = NULL;
    *pointer_to_current_entry = new_entry;

    d->num_entries++;

    return 0;
}

int dict_get(dict *d, dict_key key, dict_value *value) {
    *value = 0;

    dict_hash_type hash = word_hash(key);
    if (hash == -1) {
        return -1;
    }
    size_t bucket = hash % d->contents_size;

    dict_entry **pointer_to_current_entry = &(d->contents[bucket]);
    while (*pointer_to_current_entry) {
        dict_entry *current_entry = *pointer_to_current_entry;
        int result = word_equal(current_entry->key, key);
        if (result == -1) {
            return -1;
        }
        else if (result == 1) {
            *value = current_entry->value;
            return 1;
        }
        pointer_to_current_entry = &(current_entry->next);
    }

    return 0;
}


dict_iterator *dict_iterator_new(dict *d) {
    dict_iterator *result = malloc(sizeof(dict_iterator));
    if (result == NULL) {
        return NULL;
    }
    result->position = 0;
    result->current_key = NULL;
    return result;
}

void dict_iterator_free(dict_iterator *it) {
    if (it->current_key) {
        word_free(it->current_key);
    }
    free(it);
}

int dict_iterator_next(dict_iterator *it, dict_key *key) {
    if (it->current_key) {
        word_free(it->current_key);
        it->current_key = NULL;
    }
    int result = -1;
    const char *string;
    switch (it->position) {
        case 0: string = SINGLE_KEY; break;
        case 1: string = DUMMY_KEY; break;
        default:
            *key = NULL;
            return 0;
    }
    it->current_key = word_alloc();
    if (!it->current_key) {
        goto finally;
    }
    for (; *string; string++) {
        if (word_add_char(it->current_key, *string) < 0) {
            goto finally;
        }
    }
    it->position++;

    *key = it->current_key;
    result = 1;
finally:
    return result;
}


