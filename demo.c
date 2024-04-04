#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t delka_retezce(char *retezec) {
    size_t delka;
    for (delka = 0; *retezec; delka++, retezec++) {
        // pass
    }

    return delka;
}


char* alokuj_pamet(char *retezec) {
    size_t delka = delka_retezce(retezec);
    char *buf = malloc(delka);
    strcpy(buf, retezec);
    return buf;
}


// volat free()!
char *nazev_jednoducheho_cisla(int n) {
    switch (n) {
        case 0: return alokuj_pamet("nula");
        case 1: return alokuj_pamet("jedna");
        case 2: return alokuj_pamet("dva");
        case 3: return alokuj_pamet("tri");
        case 4: return alokuj_pamet("ctyri");
        case 5: return alokuj_pamet("pet");
        case 6: return alokuj_pamet("sest");
        case 7: return alokuj_pamet("sedm");
        case 8: return alokuj_pamet("osm");
        case 9: return alokuj_pamet("devet");
        case 10: return alokuj_pamet("deset");
        case 11: return alokuj_pamet("jedenact");
        case 12: return alokuj_pamet("dvanact");
        case 13: return alokuj_pamet("trinact");
        case 14: return alokuj_pamet("ctrnact");
        case 15: return alokuj_pamet("patnact");
        case 16: return alokuj_pamet("sestnact");
        case 17: return alokuj_pamet("sedmnact");
        case 18: return alokuj_pamet("osmnact");
        case 19: return alokuj_pamet("devatenact");
        case 20: return alokuj_pamet("dvacet");
        case 30: return alokuj_pamet("tricet");
        case 40: return alokuj_pamet("ctyricet");
        case 50: return alokuj_pamet("padesat");
        case 60: return alokuj_pamet("sedesat");
        case 70: return alokuj_pamet("sedmdesat");
        case 80: return alokuj_pamet("osmdesat");
        case 90: return alokuj_pamet("devadesat");
        default: return alokuj_pamet("nevim dal");
    }
}


char *jmeno_cisla(int cislo) {
    if (cislo <= 20) {
        return nazev_jednoducheho_cisla(cislo);
    }
    int desitky = cislo / 10;
    int jednotky = cislo % 10;
    if (jednotky == 0) {
        return nazev_jednoducheho_cisla(cislo);
    }

    char *jmeno_desitek = nazev_jednoducheho_cisla(desitky * 10);
    size_t delka_desitek = delka_retezce(jmeno_desitek);
    char *jmeno_jednotek = nazev_jednoducheho_cisla(jednotky);
    size_t delka_jednotek = delka_retezce(jmeno_jednotek);
    char *buf = malloc(delka_desitek + delka_jednotek + 2);
    strcpy(buf, jmeno_desitek);

    buf[delka_desitek] = ' ';
    strcpy(buf + delka_desitek + 1, jmeno_jednotek); 

    return buf;

}


int main() {
    for (int cislo = 0; cislo < 100; cislo++) {
        char *jmeno = jmeno_cisla(cislo);
        printf("%d %s\n", cislo, jmeno);
        free(jmeno);
    }
    return 0;
}
