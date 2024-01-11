#include <stdio.h>

int main() {
    int a = 1;
    printf("Hodnota promenne je %d\n", a);
    a = 2;
    printf("Hodnota promenne je %d\n", a);

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
    return 0;
}
