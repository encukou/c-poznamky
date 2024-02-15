#include <stdio.h>
#include <stdbool.h>
#include <math.h> 
#include "demo.h"   // lokalni soubory v " ", systemove v <>

int g = 3;

void pricti_jedna(int *p) {
    *p = *p + 1;
    printf("nove x je %d\n", *p);
}

void podil_a_zbytek(int a, int b, int *adresa_podilu, int *adresa_zbytku) {
    *adresa_podilu = a/b;
    *adresa_zbytku = a%b;
}

int main() {
    int i = 6;
    printf("%d\n", i);

    // int * - misto v pameti, kde je ulozene cele cislo
    int *ptr = &i;

    // void * - misto v pameti, o kterem nic nevim
    // ma to smysl jen jako vypsani
    printf("%p\n", (void *)ptr);

    printf("%p\n", (void *)&g);

    // dereference - jaka je hodnota, na kterou ukazuje ten ukazatel
    // *ptr
    int vysledek = *ptr + 1;
    printf("%d\n", vysledek);

    *ptr = 8;
    printf("%d\n", i);
    pricti_jedna(&i);
    printf("%d\n", i);

    int podil;
    int zbytek;
    podil_a_zbytek(70, 3, &podil, &zbytek);
    printf("podil je %d\n", podil);
    printf("zbytek je %d\n", zbytek);

    int **pp = &ptr;

    return 0;
}
