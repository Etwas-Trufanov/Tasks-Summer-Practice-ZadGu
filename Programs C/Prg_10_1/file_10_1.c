#include "file_10_1.h"
#include <stdio.h>

void Solve(char *filename, int num) {
    FILE *file = fopen(filename, "w");  // Объявляем файл и прикрепляем его в режиме записи
    for (int i = 1; i < (num+1); i++) { // Цикл записи
        char message[50];
        sprintf(message, "%i\n", i*i);
        fputs(message, file);
    }
    fclose(file);   // Обязательно закрываем файл
}
