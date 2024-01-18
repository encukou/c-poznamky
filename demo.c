// gcc -Wall -Werror --std=c17 demo.c -o demo
// show me all warnings, treat warnings as errors, 
// check whether the standard is followed (c17)
//  -pedantic -- 

/* multiline
comment goes
like this */

#include <stdio.h>

//  global variables when initialized always have a value 0
int a;

int main() {
    printf("variable value is %d\n", a);
    int b = 0;
    printf("variable value is %d\n", b);
    b = 2;
    printf("variable value is %d\n", b);
    const int c = 0;

    return 0;
}
