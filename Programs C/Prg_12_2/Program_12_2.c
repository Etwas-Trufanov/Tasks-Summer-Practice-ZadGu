/*
 * Труфанов В. М.
 * 541б
 * Список чисел -> сначала в обратном порядке отрицательные, потом положительные
 */

#include <stdio.h>
#include <stdlib.h>
#include "list_12_2.h"

int main(int argc, char **argv) {
    if (argc != 2) {                            // Проверяем на аргументы
        printf("Usage: %s count\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[1]);                  // Получаем количество
    Node *Head = NULL;                          // Создаём голову списка

    for (int i = 0; i < count; i++) {           // Заполняем его
        int temp = 0.0;
        scanf("%i", &temp);
        AddNode(&Head, temp);
    }

    listSort(&Head);                            // Сортируем

    printf("===   Output   ===\n");
    printList(&Head);                           // Выводим

    Node *current = Head;
    while (current != NULL) {                   // Очищаем память
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
