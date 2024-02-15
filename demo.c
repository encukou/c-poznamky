#include <stdio.h>
#include <stdbool.h>
#include <math.h> 
#include "demo.h"   // lokalni soubory v " ", systemove v <>

// const int CENA = 25;
#define CENA 25
#define CENA 25 + 5  // to je spatne, bere se doslova
#define CENA (25 + 5) // delat spis toto
#define MOCNINA(x) x*x*x


int main() {
    printf("%d\n", treti_mocnina(5+1));
    printf("%d\n", absolutni_hodnota(5+1));
    printf("%d\n", absolutni_hodnota(-5+1));
    int i = 7;
    printf("%d\n", zvetsi(i));
    printf("%d\n", i);
    vypis_cislo(i);

    printf("%f\n", sin(1));

#ifdef POUZIJ_MAKRO
    printf("mocnina je %d\n", MOCNINA(3));
#else
    printf("mocnina je %d\n", 4*4*4);
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