/* A data type and functions for working with short, growable strings */
#include <stdint.h>

typedef struct word word;
typedef intptr_t word_hash_type;

word *word_alloc(void);
void word_free(word *w);

// return 0 on success, -1 on error
int word_add_char(word *w, char c);

// return NULL on error
char *word_get_data(word *w);

size_t word_size(word *w);


// D.Ú.: (+testy, +použití word_from_string)

// 1 = equal, 0 = not, -1 = error
int word_equal(word *a, word *b);

// -1 = error, anything else = value
word_hash_type word_hash(word *w);

// NULL on error
word *word_from_string(char *contents);
