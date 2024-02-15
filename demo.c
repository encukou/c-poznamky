#include <stdio.h>
#include <stdbool.h>
#include <math.h> 
#include "demo.h"   // lokalni soubory v " ", systemove v <>

int g = 3;

int recurse(int level) {
    int i = 6;
    printf("level %d - adresa %p\n", level, &i);

    if (level > 0) {
        recurse(level -1);
    }
}

int main() {
    int i = 6;
    int j = 6;
    int k = 6;
    int l = 6;

    printf("%d\n", i);

    printf("%p\n", &i);
    printf("%p\n", &j);
    printf("%p\n", &k);
    printf("%p\n", &l);

    printf("%p\n", &g);

    recurse(5);
    printf("\n");
    recurse(5);

    return 0;
}
