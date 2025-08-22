/*
 * Труфанов В.М.
 * 440Б
 * Найти все отрезки, вершины которых 5 в степени
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "check_for_degree.h"   // Для CheckVerticles


void solve() {
    // Объявляем переменные
    unsigned* massive = NULL;
    int elementsNumber = 0;
    int num;    // считываемое число
    puts("Write verticles, -1 for end");
    do {
        scanf("%i", &num);
        if (num != -1) {
            elementsNumber++;
            int* temp;
            temp = realloc(massive, sizeof(unsigned) * (elementsNumber));
            massive = temp;
            massive[elementsNumber-1] = num;
        }
    } while (num != -1);
    int lowPos = 0;
    for (int hightPos = 1; hightPos < elementsNumber; hightPos++) {
        if ((CheckVerticles(massive[lowPos]) == 1) && (CheckVerticles(massive[hightPos]) == 1)) {
            printf("Verticles of segment is power of 5\n%i, %i\n", massive[lowPos], massive[hightPos]);
        }
        lowPos++;
    }
    free(massive);
}


int main() {
    assert(CheckVerticles(5) == 1);
    assert(CheckVerticles(25) == 1);
    assert(CheckVerticles(625) == 1);
    assert(CheckVerticles(390625) == 1);
    solve();
    return 0;
}
