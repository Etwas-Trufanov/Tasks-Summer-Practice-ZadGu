/*
 * Труфанов В. М.
 * Задача 474б
 * Надо вывести n^2 в файл
*/

// Подключаем библиотеки
#include <stdio.h>
#include <stdlib.h>


// Главная функция
int main(int argc, char **argv) {
    if (argc != 3) {        // Проверяем на аргументы
        printf("Usage: %s filename number\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];   // Объявляем имя файла
    int num = atoi(argv[2]);    // Объявляем кол-во элементов
    FILE *file = fopen(filename, "w");  // Объявляем файл и прикрепляем его в режиме записи
    for (int i = 1; i < (num+1); i++) { // Цикл записи
        char *message;
        sprintf(message, "%i\n", i*i);
        fputs(message, file);
    }
    fclose(file);   // Обязательно закрываем файл
    return 0;       // Возвращаем 0
}
