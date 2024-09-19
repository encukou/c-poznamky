#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
    size_t allocated;
} word;

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



const char INPUT_FILE_NAME[] = "rur-processed.txt";

const size_t BUF_SIZE = 1024;

int main(void) {
    int result = 1;
    FILE* soubor = NULL;
    word *current_word = NULL;
    char buffer[BUF_SIZE + 1];

    soubor = fopen(INPUT_FILE_NAME, "r");
    if (!soubor) {
        fprintf(stderr, "could not open file %s\n", INPUT_FILE_NAME);
        goto finally;
    }
    size_t read_count;
    current_word = word_alloc();
    if (!current_word) {
        fprintf(stderr, "could not allocate memory\n");
        goto finally;
    }
    while ((read_count = fread(buffer, 1, BUF_SIZE, soubor))) {
        printf("Nacetl jsem %zd bajtu!\n", read_count);
        buffer[read_count] = 0;
        for (size_t i = 0; i < read_count; i++) {
            char c = buffer[i];
            if ((c == ' ') || (c == '\n')) {
                if (word_size(current_word)) {
                    char *data = word_get_data(current_word);
                    if (!data) {
                        fprintf(stderr, "could not get word data\n");
                        goto finally;
                    }
                    printf("slovo: %s\n", data);
                    word_free(current_word);
                    current_word = word_alloc();
                    if (!current_word) {
                        fprintf(stderr, "could not allocate memory\n");
                        goto finally;
                    }
                }
            } else {
                if (word_add_char(current_word, c) < 0) {
                    fprintf(stderr, "could not add character to word\n");
                    goto finally;
                }
            }
        }
    }
    if (word_size(current_word)) {
        char *data = word_get_data(current_word);
        if (!data) {
            fprintf(stderr, "could not get word data\n");
            goto finally;
        }
        printf("slovo: %s\n", data);
    }

    result = 0;
finally:
    if (soubor) {
        fclose(soubor);
    }
    if (current_word) {
        word_free(current_word);
    }
    return result;
}
