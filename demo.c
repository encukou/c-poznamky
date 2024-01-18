#include <stdio.h>

int main() {
    long int a = 1;
    printf("variable value is %d\n", a);
    a = (long int)"dva";
    printf("variable value is %d\n", a);
    printf("Size of int is %zd\n", sizeof(int));

    char c = 50;
    c+= 5000;
    printf("c=%d\n", c);

    return 0;
}
