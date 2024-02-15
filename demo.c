#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "demo.h"

int g = 3;

void pricti_jedna(int *p) {
    *p = *p + 1;
    printf("nove *p je %d\n", *p);
}

void podil_a_zbytek(int a, int b, int *adresa_podilu, int *adresa_zbytku) {
    *adresa_podilu = a / b;
    *adresa_zbytku = a % b;
}

int main() {
    int i = 6;
    printf("%d\n", i);

    int *ptr = &i;

    printf("%p\n", (void *)ptr);
    printf("%p\n", (void *)&g);

    int vysledek = (*ptr) + 1;

    printf("%d\n", vysledek);

    *ptr = 8;

    printf("%d\n", i);

    //int *ptr2 = NULL;
    //printf("%d\n", *ptr2);

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
