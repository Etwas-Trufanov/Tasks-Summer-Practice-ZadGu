/*
 * Труфанов В. М.
 * Получить матрицу "змейкой"
 * 691б
 * 2 1 0
 * 3 4 5     <- типо такого
 * 8 7 6
*/

// Подключаем библиотеки
#include <stdio.h>
#include <stdlib.h>
#include "snakematrix.h"

// Главная функция
int main(int argc, char **argv) {

    if (argc != 2) {    // Проверяем параметры
        printf("Usage: %s matrix_size\n", argv[0]);
        return 1;
    }

    unsigned size = atoi(argv[1]);  // Записываем размер матрицы
    solve(size);        // Решаем задачу

    return 0;           // Возвращаем 0
}
