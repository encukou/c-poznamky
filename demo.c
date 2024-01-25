#include <stdio.h>

int a = 0;

int main() {
    {
        int a = 0;
        //const int b = 0;
        printf("Hodnota lok. promenne je %d\n", a);
        a = 2;
        printf("Hodnota lok. promenne je %d\n", a);
    }
    printf("Hodnota glob. promenne je %d\n", a);

    {
        int cislo = 1;
        while (cislo <= 5) {
            printf("%d\n", cislo);
            cislo++;
        }
    }

    //   inicializace   podminka   aktualizace
    for (int cislo = 0; cislo < 5; cislo++) {
        printf("%d\n", cislo);
    }

    {
        int cislo = 1;
        do {
            printf("%d\n", cislo);
            cislo++;
        } while (cislo <= 5);
    }

    char c = 0;
    while (c >= 0) {
        c++;
        printf("%d\n", c);
    }

/*
    printf("Velikost int je %zd\n", sizeof(int));
    printf("Velikost a je %zd\n", sizeof(a));
    printf("Velikost retezce je %zd\n", sizeof(".."));
    printf("Velikost long int je %zd\n", sizeof(long int));
    printf("Velikost short int je %zd\n", sizeof(short int));
    printf("Velikost char je %zd\n", sizeof(char));
    printf("Velikost sizeof je %zd\n", sizeof(sizeof(char)));
    printf("Velikost size_t je %zd\n", sizeof(size_t));

    char c = 50;
    printf("c=%d\n", c);
    c += 5000;
    printf("c=%d\n", c);
*/

    return 0;
}
