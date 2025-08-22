#include "solve_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Процедура нахождения самой длинной строки
// filename - имя файла
// maxLengthOut и maxPosOut - указатели куда будут возвращены значения
void getMaxLineFromFile(char *filename, int *maxLengthOut, int *maxPosOut, int maxStrRead) {
    FILE *file = fopen(filename, "r");  // Объявляем файл и прикрепляем его в режиме чтения
    char buffer[maxStrRead];

    for (int i = 0; i < maxStrRead; i++) buffer[i] = 0;

    int maxLen = 0;
    int maxLine = 0;
    int tempLinePos = 0;

    while((fgets(buffer, maxStrRead, file))!=NULL) { // Цикл чтения
        tempLinePos++;
        if (maxLen < strlen(buffer)) {
            maxLen = strlen(buffer);
            maxLine = tempLinePos;
        }
        for (int i = 0; i < maxStrRead; i++) buffer[i] = 0;
    }
    fclose(file);   // Обязательно закрываем файл
    *maxLengthOut = maxLen;      // Передаём значения
    *maxPosOut = maxLine;
}
