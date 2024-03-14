#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "demo.h"

// vraci staticky retezec, nevolat free()
char *nazev_jednoducheho_cisla(int n) {
    switch (n) {
        case 0: return "nula";
        case 1: return "jedna";
        case 2: return "dva";
        case 3: return "tri";
        case 4: return "ctyri";
        case 5: return "pet";
        case 6: return "sest";
        case 7: return "sedm";
        case 8: return "osm";
        case 9: return "devet";
        case 10: return "deset";
        case 11: return "jedenact";
        case 12: return "dvanact";
        case 13: return "trinact";
        case 14: return "ctrnact";
        case 15: return "patnact";
        case 16: return "sestnact";
        case 17: return "sedmnact";
        case 18: return "osmnact";
        case 19: return "devatenact";
        case 20: return "dvacet";
        case 30: return "tricet";
        case 40: return "ctyricet";
        case 50: return "padesat";
        case 60: return "sedesat";
        case 70: return "sedmdesat";
        case 80: return "osmdesat";
        case 90: return "devadesat";
        default: return "nevim dal";
    }
}

size_t delka_retezce(char *retezec) {
    // Delka vcetne koncoveho nuloveho znaku
    return strlen(retezec) + 1;
    // size_t i;
    // for (i = 0; retezec[i]; i++) {
    //     // nic
    // }
    // return i + 1;
}

// je potreba zavolat free(); NULL znamena chybu
char *nazev_cisla(int i) {
    if (i < 0) {
        return NULL;
    }
    if (i >= 100) {
        return NULL;
    }
    if (i <= 20) {
        char *nazev = nazev_jednoducheho_cisla(i);
        size_t delka = delka_retezce(nazev);
        char *buf = malloc(delka);
        memcpy(buf, nazev, delka);
        return buf;
    }
    int desitky = i / 10;
    int jednotky = i % 10;
    char *nazev_desitky = nazev_jednoducheho_cisla(desitky * 10);
    size_t delka_desitky = delka_retezce(nazev_desitky);
    if (jednotky == 0) {
        char *buf = malloc(delka_desitky);
        memcpy(buf, nazev_desitky, delka_desitky);
        return buf;
    }
    char *nazev_jednotky = nazev_jednoducheho_cisla(jednotky);
    size_t delka_jednotky = delka_retezce(nazev_jednotky);
    char *buf = malloc(delka_desitky + delka_jednotky);
    memcpy(buf, nazev_desitky, delka_desitky);
    buf[delka_desitky - 1] = ' ';
    memcpy(buf + delka_desitky, nazev_jednotky, delka_jednotky);

    return buf;
}

int main() {
    for (int i = -10; i <= 100; i++) {
        char *nazev = nazev_cisla(i);
        if (nazev == NULL) {
            printf("%d: chyba!\n", i);
        } else {
            printf("%d: %s\n", i, nazev);
            free(nazev);
        }
    }

    if ('a' == 97) {
        printf("Jo!\n");
    }

    if ('\0' == 0) {
        printf("Jo!\n");
    }

    return 0;
}
