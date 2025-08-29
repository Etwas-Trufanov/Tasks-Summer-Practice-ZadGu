/*
 * Труфанов В. М.
 * 136м
 * sin|a1+..+an|
*/

#include <stdio.h>
#include <stdlib.h>
#include "list_12_1.h"

int main(int argc, char **argv) {
    if (argc != 2) {    // Проверяем на кол-во аргументов
        printf("Usage: %s count\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[1]);  // Записываем кол-во элементов
    Node *head = NULL;          // Создаём голов списка

    for (int i = 0; i < count; i++) {   // Заполняем список
        float temp = 0.0;
        scanf("%f", &temp);
        head = AddNode(head, temp);
    }

    float result = calcListSin(head);   // Получаем синус списка
    freeList(head);
    printf("%f\n", result);             // Выводим результат

    return 0;                           // Возвращаем 0
}
