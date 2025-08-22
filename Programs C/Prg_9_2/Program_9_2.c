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
#include "snakematrix.h"    // Для generateMatrix

// Процедура решения
void solve(char **argv) {
    unsigned scale = atoi(argv[1]); // Получаем размер
    int matrix[scale][scale];       // Объявляем матрицу
    generateMatrix(scale, matrix);  // Заполняем её
    for (int y = 0; y < scale; y++) {       // Выводим
        for (int x = 0; x < scale; x++) {
            printf("%3i ", matrix[y][x]);
        }
        printf("\n");
    }
}


// Главная функция
int main(int argc, char **argv) {
    if (argc != 2) {    // Проверяем параметры
        printf("Usage: %s matrix_size\n", argv[0]);
        return 1;
    }
    solve(argv);        // Решаем задачу
    return 0;           // Возвращаем 0
}
