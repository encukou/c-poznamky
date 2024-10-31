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
    // to be continued

}

int dict_get(dict *d, dict_key key, dict_value *value) {
    int result = -1;
    char *key_data = word_get_data(key);
    if (!key_data) {
        *value = -1;
        goto finally;
    }
    if (strcmp(key_data, SINGLE_KEY) == 0) {
        *value = d->count;
        result = 1;
    } else {
        *value = -1;
        result = 0;
    }
finally:
    return result;
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


