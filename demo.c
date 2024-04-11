#include <stdio.h>

char *haha = "haha";

typedef enum {
    KOTATKO = 6,
    STENATKO,
} Druh;

typedef struct Zviratko {
    Druh druh;
    const char *jmeno;
    void (*udelej_zvuk)(const struct Zviratko*);
} Zviratko;

typedef struct {
    Zviratko zvire;
    const char *barva;
    int vek;
} Kotatko;

typedef struct {
    Zviratko zvire;
    const char *oblibena_hracka;
} Stenatko;

void zamnoukej(const Zviratko *k) {
    printf("%s: mnau!\n", k->jmeno);
}

void zastekej(const Zviratko *z) {
    if (z->druh == STENATKO) {
        Stenatko *stene = (Stenatko*)z;
        printf("%s: haf! Hraju si s %s\n", z->jmeno, stene->oblibena_hracka);
    } else {
        printf("%s se snazi stekat ale moc to nejde\n", z->jmeno);
    }
}

void udelej_zvuk(const Zviratko *z) {
    z->udelej_zvuk(z);
}

typedef void (*ukazatel_na_funkci_ktera_bere_zvire_a_vraci_void)(const Zviratko *);

int main() {
    Kotatko mourek = {
        {.jmeno = "mourek", .druh=KOTATKO, .udelej_zvuk=zamnoukej},
        .barva = "bila",
        .vek = 5,
    };
    zamnoukej((Zviratko*)&mourek);
    zastekej((Zviratko*)&mourek);

    mourek.zvire.udelej_zvuk((Zviratko*)&mourek);
    udelej_zvuk((Zviratko*)&mourek);

    Stenatko azor = {
        .zvire = {STENATKO, "azor", zastekej},
        "kost"
    };
    zastekej((Zviratko*)&azor);

    azor.zvire.udelej_zvuk((Zviratko*)&azor);

    ukazatel_na_funkci_ktera_bere_zvire_a_vraci_void udelej_zvuk = zastekej;

    udelej_zvuk((Zviratko*)&azor);

    void (*f)(const Zviratko*) = zamnoukej;
    f((Zviratko*)&mourek);

    printf("zastekej: %p\n", (void*)&zastekej);
    printf("zamnoukej: %p\n", (void*)&zamnoukej);
    printf("main: %p\n", (void*)&main);
}
