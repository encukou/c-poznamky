#include <stdio.h>
#include <stdbool.h>


int main() {

    printf("Velikost float je %zd\n", sizeof(float));
    printf("Velikost double je %zd\n", sizeof(double));

    float f = 1.25;
    printf("f = %f\n", f);

    f = 1L / 3.f;
    printf("f = %f\n", f);

    printf("Velikost bool je %zd\n", sizeof(bool));

    bool b = true;
    printf("b = %d\n", b);
    b = false;
    printf("b = %d\n", b);
    b = (3 == 5) || (3 == 3);  // | je pro bitove operace, || je pro ciselne
    printf("b = %d\n", b);
    b = (3 == 5) && (3 == 3);
    printf("b = %d\n", b);

    b = 8 && 3;
    printf("b = %d\n", b);

    b = 8 & 3;  // nemaji spolecny zapnuty bit
    printf("b = %d\n", b);

    b = !(3 == 3); // negace
    printf("b = %d\n", b);

    int i = -8;
    if (i) {
        printf("jo\n");
    } else {
        printf("ne\n");
    }

    b = i;
    printf("b = %d\n", b);

    printf("!!i = %d\n", !!i); // jeden ! je negace, !! je negace negaci - jak nerychleji neco prevest na bool v C

    printf("i je: %s\n", i ? "pravda" : "nepravda");

    printf("i je: %u\n", (unsigned int)i);
    printf("i je: %d\n", (bool)i);

    i = 1;
    switch (i) {
        case 0:
            printf("Je to nula\n");
            break; // nebo: fallthrough - zamerne propadni, jsou spec. priklady
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
