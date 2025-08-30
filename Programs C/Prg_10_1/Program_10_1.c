/*
 * Труфанов В. М.
 * Задача 474б
 * Надо вывести n^2 в файл
*/

// Подключаем библиотеки
#include "file_10_1.h"
#include <stdio.h>
#include <stdlib.h>


// Главная функция
int main(int argc, char **argv) {
    if (argc != 3) {        // Проверяем на аргументы
        printf("Usage: %s filename number\n", argv[0]);
        return 1;
    }
    Solve(argv[1], atoi(argv[2]));
    return 0;       // Возвращаем 0
}
