/*
 * Задание 4
 * 78a
 * Труфанов В. М.
 * Найти число a в степени n
 */

// Команды препроцессора
#include <stdio.h>      // Библиотека ввода-вывода
#include <stdlib.h>     // Для atoi

int ext(int value, int degree) {
    int num = 1;
    for (int i = 0; i < degree; i++) {
        num = num * value;
    }
    return num;
}

// Главная функция и основной код
int main(int argc, char **argv) {
    int a, n = 0;         // Объявление переменных
    if (argc != 3) {
        puts("Error: Wrong number of arguments\nProgram for raising a number to a power, first argument - value, second - dedgree");
    } else {
        a = atoi(argv[1]);            // Записываем первый аргумент
        n = atoi(argv[2]);            // Записываем второй аргумент
        printf("%i\n", ext(a, n));    // Выводим результат функции возведения числа в степень
    }
    return 0;           // Возвращаем 0
}
