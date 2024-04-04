#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    size_t delka;
    for (delka = 0; *retezec; delka++, retezec++) {
        // pass
    }

    return delka;
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
