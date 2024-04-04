#include <stdio.h>

typedef char * Retezec;

// struct Prisera {
//     Retezec jmeno;
//     int pocet_zivotu;
//     int zraneni;
//     int pozice_x;
//     int pozice_y;
// };
// typedef struct Prisera Prisera;

// ekvivalent to:

typedef struct {
    Retezec jmeno;
    int pocet_zivotu;
    int zraneni;
    int pozice_x;
    int pozice_y;
} Prisera;


void vypis_priseru(Prisera *p) {
    printf("Prisera %s, %d/%d. na pozici %d, %d\n",
    (*p).jmeno, // p->jmeno je to same co dereferencovani (*p).
    p->pocet_zivotu - (*p).zraneni,
    (*p).pocet_zivotu,
    (*p).pozice_x,
    (*p).pozice_y);
}

int main() {

    Prisera karel = {
        .jmeno = "Karel", 
        .pocet_zivotu = 28,
        .zraneni = 2,
        .pozice_x = 6,
        .pozice_y = 8,
    };

    vypis_priseru(&karel);
    Retezec jmeno = "Vera";
    printf("%s\n", jmeno);

}
