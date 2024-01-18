#include <stdio.h>


int main() {
    {
        int cislo = 1;
        while (cislo <= 50) {
            printf("%d\n", cislo);
            // increment 1
            cislo++;
            // alternatively: cislo += 1
        if (cislo > 5) {
            break;
        }
        }
    }

    {
        int cislo = 1;
        do {
            printf("%d\n", cislo);
            cislo++;
        } while (cislo <= 5);
    }

    {
        int cislo = 1;
        for (int cislo = 1; cislo <= 5; cislo++) {
            if (cislo == 3) {
                continue;
            }
            printf("%d\n", cislo);
        }
    }

    return 0;
}
