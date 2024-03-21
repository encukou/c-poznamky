#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h> 
#include "demo.h"   // lokalni soubory v " ", systemove v <>

char *nazev_cisla(int i) {
    switch (i) {
        case 0: return "Nula";
        case 1: return "Jedna";
        default: return "Nevim";
    }
}
void leak() {
    int *p = malloc(sizeof(int));

    *p = 8;
    printf("%d\n", *p);

    free(p);
}


int main() {
    leak();

    char *nazev = nazev_cisla(1);
    printf("%s\n", nazev);
    return 0;
}
