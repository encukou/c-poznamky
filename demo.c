#include <stdio.h>
#include <stdbool.h>
#include <math.h> 
#include "demo.h"   // lokalni soubory v " ", systemove v <>

#define VELIKOST 6
// nebo:
// const int VELIKOST = 6;

#define VELIKOST_POLE(P) (sizeof(P) / sizeof((P)[0]))

int main() {

    int pole[VELIKOST] = {2, 3, 4, 5, 6, 7, -1};

    // const int velikost = VELIKOST_POLE(pole);
    // printf("%d\n", pole[0]);
    // printf("%ld\n", sizeof(pole));
    // printf("%ld\n", sizeof(pole[0]));

    // for (int i = 0; i <velikost; i++) {
    //     printf("%d\n", pole[i]);
    // }

    // // int *ptr = &pole[0];  // ptr ukazuje na prvni prvek pole
    // int *ptr = pole;  // ptr ukazuje na prvni prvek pole


    // for (int i = 0; i <velikost; i++) {
    //     printf("prvek %i je %d\n", i, *(ptr+i));
    // }

    // for (int i = 0; i <velikost; i++) {
    //     printf("prvek %i je %d\n", i, ptr[i]);
    // }

    // printf("%p ukazuje na %d\n", (void*)ptr, *ptr);

    // for (int *current = ptr; *current != -1; current++) {
    //     printf("prvek je %d\n", *current);
    // }

    char r[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // char *r = "Hello";

    for (char *current = r; *current; current++) {
        printf("prvek je %c\n", *current);
    }

    return 0;
}
