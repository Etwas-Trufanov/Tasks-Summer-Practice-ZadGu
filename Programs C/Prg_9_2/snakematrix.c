#include "snakematrix.h"
#include <stdio.h>


// Процедура генерации матрицы
void generateMatrix(int size, int matrixOut[size][size]) {
    // Число которое будем записывать
    int value = 0;
    // Направление записи
    short direction = -1;
    // Главный цикл
    for (int y = 0; y < size; y++) {
        // В зависимости от направления
        switch (direction) {
            case 1: {
                for (int x = 0; x < size; x++) {    // Если слева на право
                    matrixOut[y][x] = value;
                    value++;
                }
                direction = direction * -1;
                break;
            }
            case -1: {
                for (int x = size - 1; x > -1; x--) {   // Если справа на лево
                    matrixOut[y][x] = value;
                    value++;
                }
                direction = direction * -1;
                break;
            }
        }
    }
}


// Процедура решения
void solve(unsigned size) {

    int matrix[size][size];       // Объявляем матрицу

    generateMatrix(size, matrix);  // Заполняем её

    for (int y = 0; y < size; y++) {       // Выводим
        for (int x = 0; x < size; x++) {
            printf("%3i ", matrix[y][x]);
        }
        printf("\n");
    }
}
