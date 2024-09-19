#include <stdio.h>

#include "word.h"


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
