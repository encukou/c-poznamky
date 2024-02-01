#include <stdio.h>
#include <limits.h>
#include <stdint.h>

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

    int a = 2147483647;
    printf("max.hodnota int je %d\n", a);
    a = -2147483648;
    printf("min.hodnota int je %d\n", a);
    printf("min.hodnota int je %d\n", INT_MIN);

    unsigned u = 4294967295;
    printf("max.hodnota unsigned int je %u\n", u);
    u = 0;
    printf("min.hodnota unsigned int je %u\n", u);

    int x = 0b0011;
    int y = 0b1010;
    printf("    x = %5d\n", x);
    printf("    y = %5d\n", y);

    printf("    x = %32b\n", x);
    printf("    y = %32b\n", y);

    printf("x & y = %32b\n", x & y);
    printf("x | y = %32b\n", x | y);
    printf("   ~x = %32b\n", ~x);
    printf("x ^ y = %32b\n", x ^ y);

    printf("x << 3= %32b\n", x << 3);
    printf("y >> 2= %32b\n", y >> 2);

    uint32_t barva = 0xe51f40FF;
    printf("barva = %x\n", barva);
    printf("barva = %X\n", barva);
    unsigned char cervena = (barva & 0xff000000) >> (8 * 3);
    printf("cervena slozka = %x\n", cervena);
    const uint32_t ZELENA_MASKA = 0x00ff0000;
    unsigned char zelena = (barva & ZELENA_MASKA) >> (8 * 2);
    printf("zelena slozka  = %x\n", zelena);
    unsigned char modra = (barva & 0x0000ff00) >> (8 * 1);
    printf("modra slozka   = %x\n", modra);
    unsigned char pruhlednost = (barva & 0x000000ff) >> (8 * 0);
    printf("pruhlednost    = %x\n", pruhlednost);

    uint32_t nova_barva = cervena << (8 * 3)
                        | zelena << (8 * 2)
                        | modra << (8 * 1)
                        | pruhlednost;
    printf("nova barva     = %x\n", nova_barva);

    printf("barva bez zelene = %x\n", barva & 0xff00ffff);
    printf("barva bez zelene = %x\n", barva & ~ZELENA_MASKA);
    printf("barva bez zelene = %x\n", barva &~ ZELENA_MASKA);

    return 0;
}
