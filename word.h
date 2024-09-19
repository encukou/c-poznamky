/* A data type and functions for working with short, growable strings */

typedef struct word word;

word *word_alloc(void);
void word_free(word *w);

// return 0 on success, -1 on error
int word_add_char(word *w, char c);

// return NULL on error
char *word_get_data(word *w);

size_t word_size(word *w);
