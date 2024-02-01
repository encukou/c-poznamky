#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    printf("Velikost int je %zd\n", sizeof(int));
    printf("Velikost long int je %zd\n", sizeof(long int));
    printf("Velikost short int je %zd\n", sizeof(short int));
    printf("Velikost unsigned char je %zd\n", sizeof(unsigned char));

    printf("Velikost long je %zd\n", sizeof(long));
    printf("Velikost short je %zd\n", sizeof(short));
    printf("Velikost long long je %zd\n", sizeof(long long));

    printf("Velikost int32_t je %zd\n", sizeof(int32_t));
    printf("Velikost uint32_t je %zd\n", sizeof(uint32_t));
    // Víc na https://en.cppreference.com/w/c/types/integer

    printf("Velikost float je %zd\n", sizeof(float));
    printf("Velikost double je %zd\n", sizeof(double));

    printf("Velikost bool je %zd\n", sizeof(bool));

    bool b = true;
    printf("b = %d\n", b);
    b = false;
    printf("b = %d\n", b);
    b = (3 == 5) || (3 == 3);
    printf("b = %d\n", b);
    b = (3 == 5) && (3 == 3);
    printf("b = %d\n", b);
    b = !(3 == 3);
    printf("b = %d\n", b);

    b = 8 && 3;
    printf("b = %d\n", b);

    b = 8 & 3;
    printf("b = %d\n", b);

    int i = -8;
    if (i) {
        printf("jo\n");
    } else {
        printf("ne\n");
    }
    b = i;
    printf("b = %d\n", b);

    printf("!!i = %d\n", !!i);

    printf("i je: %s\n", i ? "pravdivé" : "nepravdivé");

    printf("i je: %u\n", (unsigned int)i );

    double f = 3.1415926;
    int j = f;
    printf("f je: %d\n", (int)f );
    printf("f je: %d\n", (bool)f );

    f = 1 / (double)3;
    printf("f je: %f\n", f );

    i = 1;
    switch (i) {
        case 0:
            printf("Je to nula\n");
            break;
        case 1:
            printf("Je to jedna\n");
            break;
        case 2:
            printf("Je to dva\n");
            break;
        default:
            printf("Je to kdo vi co\n");
            break;
    }

    return 0;
}
