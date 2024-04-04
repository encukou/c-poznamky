#include <stdio.h>
#include <stdalign.h>
#include <stddef.h>

typedef char * Retezec;

typedef struct {
    int x;
    int y;
} Pozice;

typedef struct {
    Retezec jmeno;
    int pocet_zivotu;
    char symbol;
    // 3 nevyuzite byty
    int zraneni;
    Pozice pozice;
    char symbol2;
    // 3 nevyuzite byty
} Prisera;

void vypis_priseru(const Prisera *p) {
    printf(
        "Prisera %s, %d/%d, na pozici %d, %d\n",
        p->jmeno,       // to same jako (*p).jmeno
        p->pocet_zivotu - p->zraneni,
        p->pocet_zivotu,
        p->pozice.x,
        p->pozice.y);
    Prisera *m = (Prisera *)p;  // fuj fuj
    m->zraneni += 1;
    //p->pozice.x += 1;
}

int main() {
    unsigned long int cisla[] = {
        [0] = 5,
        [1] = 6,
        [100] = 6,
    };
    Prisera karel = {
        .jmeno = "Karel",
        .pocet_zivotu = 28,
        .pozice = {8, 6},
        .zraneni = 2,
        .symbol = 'W',
    };
    vypis_priseru(&karel);
    vypis_priseru(&karel);
    vypis_priseru(&karel);
    vypis_priseru(&karel);
    vypis_priseru(&karel);

    printf("%p\n", (void*) &karel);
    printf("%p\n", (void*) &(karel.jmeno));
    printf("%p\n", (void*) &(karel.pocet_zivotu));
    printf("%p\n", (void*) &(karel.symbol));
    printf("%p\n", (void*) &(karel.zraneni));

    printf("%i\n", (int) sizeof(karel.zraneni));
    printf("%i\n", (int) alignof(int));
    printf("%i\n", (int) offsetof(Prisera, zraneni));

    char *p = (char *)&karel;
    p += offsetof(Prisera, zraneni);
    *p = 28;  // zapise 1 byte
    *(int*)p = 28;  // zapise 4 byty

    vypis_priseru(&karel);

    Pozice pozice = {6, 8};
    pozice.y += 1;

    Retezec jmeno = "Vera";
    printf("%s %d\n", jmeno, (int)sizeof(Prisera));
}
