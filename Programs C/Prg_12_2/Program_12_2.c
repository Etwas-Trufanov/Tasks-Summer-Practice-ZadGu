/*
 * Труфанов В. М.
 * 541б
 * Список чисел -> сначала в обратном порядке отрицательные, потом положительные
 */

#include <stdio.h>
#include <stdlib.h>
#include "list_12_2.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s count\n", argv[0]);
        return 1;
    }

    // Указатель на голову списка
    Node *Head;
    // Количество элементов
    int Count = atoi(argv[1]);

    // Считываем числа и добавляем их в список
    for (int i = 0; i < Count; i++) {
        int temp;
        scanf("%i", &temp);
        Head = AddNode(Head, temp);
    }

    Head = SortList(Head);

    PrintList(Head);

    Node *Current = Head;
    while (Current != NULL) {
        Head = Current->next;
        free(Current);
        Current = Head;
    }

    return 0;
}
