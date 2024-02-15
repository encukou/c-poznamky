#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "demo.h"

//const int CENA = 25;
//#define CENA 25
#define MOCNINA(x)  x  * x * x

int main() {
    printf("cena je %d\n", CENA);
    printf("dvakrat cena je %d\n", CENA*2);
    printf("%d\n", absolutni_hodnota(-5 + 1));
    int i = 6;

#if 3 < 5
    printf("jo\n");
#endif

#ifdef POUZIJ_MAKRO
    printf("mocnina je %d\n", MOCNINA(3));
#else
    printf("mocnina je %d\n", 4 * 4 * 4);
#endif

    return 0;
}

int treti_mocnina(int cislo) {
    return cislo * cislo * cislo;
}

int absolutni_hodnota(int cislo) {
    if (cislo < 0) {
        return -cislo;
    }
    return cislo;
}

int zvetsi(int cislo) {
    cislo++;
    return cislo;
}

void vypis_cislo(int cislo) {
    printf("%d\n", cislo);
}
