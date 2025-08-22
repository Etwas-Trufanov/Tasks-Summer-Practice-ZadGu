/*
 * Труфанов В. М.
 * Задача 522
 * Получить самую длинную строку
 * �������� Не работает по нормальному с русским языком �������������
*/

// Подключаем библиотеки
#include <stdio.h>
#include <stdlib.h>
#include "solve_module.h"


// Главная функция
int main(int argc, char **argv) {
    const int maxsize = 256;
    if (argc != 2) {        // Проверяем на аргументы
        printf("Usage: %s filename.type\n", argv[0]);
        return 1;
    }

    int maxLen = 0;
    int maxLine = 0;

    getMaxLineFromFile(argv[1], &maxLen, &maxLine, maxsize);

    printf("Max length of line: %i\nLine: %i\n", maxLen, maxLine);
    return 0;       // Возвращаем 0
}
