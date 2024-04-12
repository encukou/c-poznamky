#include <stdio.h>

const int KOTATKO = 1;
const int STENATKO = 2;


typedef struct {
    int druh;
    const char *jmeno;
} Zviratko;

typedef struct {
    Zviratko z;
    const char *barva;
} Kotatko;

typedef struct {
    Zviratko z;
    const char *oblibena_hracka;
} Stenatko;

void zamnoukej(Kotatko *k) {
    printf("%s: mnau!\n", k->z.jmeno);
}

void zastekej(Zviratko *z) {
    if (z->druh == STENATKO) {
        Stenatko *stene = (Stenatko*)z;
        printf("%s: haf! Hraju si s %s\n", z->jmeno, stene->oblibena_hracka);
    } else {
        printf("%s: se snazi stekat, ale to nejde\n", z->jmeno);
    }
    
}

int main() {
    Kotatko mourek = {
        {.jmeno = "mourek", .druh=KOTATKO},
        .barva = "bila",
    };
    zamnoukej(&mourek);
    zastekej(&(mourek.z));

    Stenatko azor = {
        .z = {STENATKO, "azor"},
        "kost"
    };
    zastekej(&azor.z);

    udelej_zvuk = zastekej;
    udelej_zvuk((Zviratko*)&azor);

    printf("zastekej: %p\n", (void*)&zastekej);
    printf("zamnoukej: %p\n", (void*)&zamnoukej);
    printf("main: %p\n", (void*)&main);

}
