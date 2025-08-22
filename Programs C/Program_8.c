/*
 * Задача взята с потолка
 * Труфанов В.М.
 * 683б
 * Переставить две строки и два столбца так чтобы наименьший элемент был в левом нижнем углу матрицы
 */

#include <stdio.h>  // Для printf
#include <time.h>   // чтобы использовать функцию time()
#include <stdlib.h> // Для rand, srand

#define MAX_VALUE 101;

// Небольшая процедурка которая красиво выводит матрицу
void printMatrix(int scale, int Matrix[][scale]) {
    printf("   | ");
    for (int i = 0; i <scale; i++) printf("%3i ", i);
    printf("\n");
    printf("-----");
    for (int i = 0; i <scale; i++) printf("----");
    printf("\n");
    for (int i = 0; i < scale; i++) {
        printf("%3i| ", i);
        for (int j = 0; j < scale; j++) {
            printf("%3i ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));              // Меняем семя генерации
    if (argc != 2) {                // Проверяем на аргументы
        printf("Usage: %s matrix_size\n", argv[0]);
        return 1;
    }
    int scale = atoi(argv[1]);      // Считываем размер
    int matrix[scale][scale];       // Объявляем матрицу
    for (int i = 0; i < scale; i++) {           // Заполняем матрицу
        for (int j = 0; j < scale; j++) {
            matrix[i][j] = rand() % MAX_VALUE;        // Макс значение 100
        }
    }
    printMatrix(scale, matrix);     // Выводим матрицу
    int minX, minY = 0;             // Объявляем позицию и само самое малое число
    int minNum = matrix[0][0];
    for (int y = 0; y < scale; y++) {       // Находим наименьшее число и его позицию
        for (int x = 0; x < scale; x++) {
            if  (minNum > matrix[y][x]) {
                minNum = matrix[y][x];
                minY = y;
                minX = x;
            }
        }
    }
    // Выводим информацию о найденном числе
    printf("\nMinimal value %i, on position %i %i\n\n", minNum, minX, minY);
    int tempCR[scale];      // Временный массив для сохранения строки\столбца
    for (int i = 0; i < scale; i++) {   // Меняем местами столбцы
        tempCR[i] = matrix[i][0];
    }
    for (int i = 0; i < scale; i++) {
        matrix[i][0] = matrix[i][minX];
    }
    for (int i = 0; i < scale; i++) {
        matrix[i][minX] = tempCR[i];
    }

    for (int i = 0; i < scale; i++) {   // Меняем местами строки
        tempCR[i] = matrix[scale-1][i];
    }
    for (int i = 0; i < scale; i++) {
        matrix[scale-1][i] = matrix[minY][i];
    }
    for (int i = 0; i < scale; i++) {
        matrix[minY][i] = tempCR[i];
    }
    printMatrix(scale, matrix);         // Выводим матрицу
    return 0;                           // Возвращаем 0
}
