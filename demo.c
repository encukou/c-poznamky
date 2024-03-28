#include <stdio.h>
#include <stdint.h>

typedef struct {
    int x;
    int y;
} Souradnice;

typedef struct {
    const char *jmeno;
    int zivot;
    int zraneni;
    Souradnice poloha;
} Prisera;

void vypis_priseru(const Prisera *prisera) {
    printf("prisera %s (%d/%d) na pozici %d,%d\n",
           prisera->jmeno,  // to same jako:  (*prisera).jmeno
           prisera->zivot - prisera->zraneni,
           prisera->zivot,
           prisera->poloha.x,
           prisera->poloha.y);
    //prisera->poloha_y += 1;
}

int main() {
    Prisera karel = {
        .jmeno = "Karel",
        .zivot = 9,
        .zraneni = 3,
        .poloha = {1, 9},
    };
    karel.poloha.y += 1;
    vypis_priseru(&karel);
    vypis_priseru(&karel);
    vypis_priseru(&karel);
    vypis_priseru(&karel);
}
