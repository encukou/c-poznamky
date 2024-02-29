#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "demo.h"

// "............"
//  dvacet devet

char *nazev_cisla(int i) {
    char *result;
    switch (i) {
        case 0: {
            result = malloc(5);
            result[0] = 'n';
            result[1] = 'u';
            result[2] = 'l';
            result[3] = 'a';
            result[4] = 0;
        } break;
        case 1: {
            result = malloc(6);
            result[0] = 'J';
            result[1] = 'e';
            result[2] = 'd';
            result[3] = 'n';
            result[4] = 'a';
            result[5] = 0;
        } break;
        case 3: {
            result = malloc(4);
            memcpy(result, "Tri", 4);
        } break;
        default: {
            result = malloc(6);
            result[0] = 'N';
            result[1] = 'e';
            result[2] = 'v';
            result[3] = 'i';
            result[4] = 'm';
            result[5] = 0;
        } break;
    }
    return result;
}

int main() {
    char *nazev = nazev_cisla(3);
    printf("%s\n", nazev);
    free(nazev);

    return 0;
}
