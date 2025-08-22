/*
 * Задание 5
 * 202б
 * Труфанов В. М.
 * Самое большое число в последовательности по модулю больше 1?
 */

// Команды препроцессора
#include <stdio.h>      // Библиотека ввода-вывода
#include <stdlib.h>     // Для atof
#include <math.h>       // Для fabs

// Получение ID самого большого элемента по модулю, arr[] - указатель на первый эл. массива, size - размер массива
float getBiggestValue(float arr[], int size) {
    int tempID = 0;
    for (int i = 1; i < size; i++) {
        if (arr[tempID] < arr[i]) {
            tempID = i;
        }
    }
    return arr[tempID];
}

// Главная функция и основной код
int main(int argc, char **argv) {
    if (argc > 1) {
        // Объявляем массив
        float values[argc-1];
        // Заполняем массив значениями, начиная с argv[1]
        for (int i = 1; i < argc; i++) {
            values[i - 1] = atof(argv[i]);
        }
        float biggestValue = getBiggestValue(values, argc - 1);     // Получаем самое большое число
        if (fabs(biggestValue) > 1) {                               // Проверяем его по модулю
            printf("Most big value in massive, absolute value bigger then 1 is %f\n", biggestValue);
        }
    }
    return 0;
}

