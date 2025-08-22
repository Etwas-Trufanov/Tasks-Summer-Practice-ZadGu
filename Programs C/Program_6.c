// Недоделана
/*
 * Задание 6
 * 338а
 * Труфанов В. М.
 * Найти все элементы что есть и в A и в B
 */

// Команды препроцессора
#include <stdio.h>      // Библиотека ввода-вывода
#include <stdlib.h>     // Для atof

// Пересечение двух множеств
// size1 и size2 - размер множеств
// arr1 и arr2 - множества
// outsize и outmass - указатели на вывод
void intersection(int s1, int mass1[], int s2, int mass2[], int *outSize, int **outmass) {
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            if (mass1[i] == mass2[j]) {
                *outSize = *outSize + 1;
                int* temp = realloc(*outmass, sizeof(int)*(*outSize));
                *outmass = temp;
                (*outmass)[*outSize-1] = mass1[i];
                break;
            }
        }
    }
}

// Главная функция и основной код
int main(int argc, char **argv) {
    // Проверка на количество аргументов
    if (argc != 3) {
        printf("Usage: %s <size1> <size2>\n", argv[0]);
        return 1;
    }
    // Объвление переменных
    // size1/2 - размеры множеств
    // massive1/2 - сами множества
    // outputSet и outputSetSize соответсвенно
    // outputSet - динамический массив
    int size1 = atoi(argv[1]);
    int size2 = atoi(argv[2]);
    int massive1[size1];
    int massive2[size2];
    int* outputSet = NULL;
    int outputSetSize = 0;
    // Просим ввести первое множество
    puts("Write elements of first set");
    for (int i = 0; i < size1; i++) {
        scanf("%i", &massive1[i]);
    }
    // Просим ввести второе множество
    puts("Write elements of second set");
    for (int i = 0; i < size2; i++) {
        scanf("%i", &massive2[i]);
    }
    // Находим пересечение
    intersection(size1, massive1, size2, massive2, &outputSetSize, &outputSet);
    // Выводим если есть значения в множестве
    if (outputSetSize != 0) {
        puts("intersection:");
        for (int i = 0; i < outputSetSize; i++) {
            printf("%i\n", outputSet[i]);
        }
    } else {
        puts("Set of intersection set 1 and set 2 is empty");
    }
    free(outputSet);
    return 0;
}
