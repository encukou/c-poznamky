#include <string.h>
#include <stdlib.h>
#include "word.h"


struct word {
    char *data;
    size_t size;
    size_t allocated;
};

word *word_alloc(void) {
    word *result = malloc(sizeof(word));
    if (!result) {
        return NULL;
    }
    result->data = NULL;
    result->size = 0;
    result->allocated = 0;
    return result;
}
void word_free(word *w) {
    free(w->data);
    free(w);
}
int word_add_char(word *w, char c) {  // return 0 on success, -1 on error
    /* - if there's not enough space for one more char
     *   - allocate a new buffer (~min. 4 chars, 2× bigger than the old one)
     *   - copy old data (if old data is not NULL)
     *   - dealloc the old buffer
     *   - set `allocated`
     * - set the new character
     * - size++
     * - ensure data is followed by NUL
     */
    if (w->size + 2 > w->allocated) {
        size_t new_allocated = w->allocated * 2;
        if (new_allocated < 4) {
            new_allocated = 4;
        }
        char *new_buf = malloc(new_allocated);
        if (!new_buf) {
            return -1;
        }
        if (w->data) {
            memcpy(new_buf, w->data, w->size);
            free(w->data);
        }
        w->data = new_buf;
        w->allocated = new_allocated;
    }
    w->data[w->size++] = c;
    w->data[w->size] = 0;
    return 0;
}
char *word_get_data(word *w) {
    /* - return data
     */
    if (!w->data) {
        return "";
    }
    return w->data;
}
size_t word_size(word *w) {
    return w->size;
}
