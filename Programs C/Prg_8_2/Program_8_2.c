/*
 * 700Б
 * Чёт про умножение матриц
*/

#include <stdio.h>
#include <stdlib.h>

// Процедурка вывода матрицы
// size - размер, matrix - матрица
void PrintMatrix(int size, float matrix[size][size]) {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            printf("%4f ", matrix[y][x]);
        }
        printf("\n");
    }
}


int main(int argc, char **argv) {
    // Проверяем на аргументы
    if (argc != 2) {
        printf("Usage: %s size", argv[0]);
        return 1;
    }

    // Получаем размер
    int size = atoi(argv[1]);

    // Объявляем матрицу А
    float matrixA[size][size];

    //Заполняем матрицу
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            scanf("%f", &matrixA[y][x]);
        }
    }

    // Объявляем матрицу B
    float matrixB[size][size];

    // Заполняем матрицу B
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y <= x) {
                matrixB[y][x] = 1.0/(y+x-1.0);
            } else {
                matrixB[y][x] = 1.0/(y+x+1.0);
            }
        }
    }

    // Выводная матрица
    float output[size][size];

    // Перемножаем матрицы (Вроде так)
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            for (int w = 0; w < size; w++) {
                output[y][x] += matrixA[y][w] *matrixB[w][x];
            }
        }
    }

    // Выводим
    PrintMatrix(size, output);

    return 0;
}
