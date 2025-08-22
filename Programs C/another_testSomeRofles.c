#include <stdio.h>

int main() {
    unsigned base = 5;
    unsigned power = 1;
    while (power < 30) {
        printf("%i, %i\n", base, power);
        base = base * base;
        power++;
    }
    return 0;
}
