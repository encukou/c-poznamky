#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "demo.h"

//#define VELIKOST 6
//const int VELIKOST = 6;
#define VELIKOST_POLE(P) (sizeof(P) / sizeof((P)[0]))


int main() {
    int pole[6] = {2, 3, 4, 5, 6, -1};

    const int velikost = VELIKOST_POLE(pole);

    printf("sizeof(pole) = %ld\n", sizeof(pole));
    printf("sizeof(pole[0]) = %ld\n", sizeof(pole[0]));

    printf("%d\n", pole[0]);

    for (int i = 0; i < velikost; i++) {
        printf("prvek %i je %d\n", i, pole[i]);
    }

    //int *ptr = &pole[0]; // ptr ukazuje na prvni prvek pole
    int *ptr = pole; // ptr ukazuje na prvni prvek pole

    for (int i = 0; i < velikost; i++) {
        printf("prvek %i je %d\n", i, *(ptr + i));
    }

    for (int i = 0; i < velikost; i++) {
        printf("prvek %i je %d\n", i, ptr[i]);
    }

    for (int *current = pole; *current != -1; current++) {
        printf("aktualni prvek je %d\n", *current);
    }

    //char r[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *r = "Hello";

    for (char *current = r; *current; current++) {
        printf("aktualni znak je %c\n", *current);
    }


    return 0;
}





