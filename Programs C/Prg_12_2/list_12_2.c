#include "list_12_2.h"
#include <stdlib.h>
#include <stdio.h>

void printList(Node **Head) {
    Node *Current = *Head;
    while (Current != NULL) {
        printf("%i\n", Current->data);
        Current = Current->next;
    }
}

// Процедура добавления элемента в список
void AddNode(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));    // Объявляем и выделяем новый элемент
    newNode->data = value;      // Заполняем его
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {        // В случае если список пуст
        *head = newNode;
    } else {
        Node *Current = *head;              // Переменная указатель
        while (Current->next != NULL) {     // Ищем хвост
            Current = Current->next;
        }
        Current->next = newNode;            // Цепляем к текущему новый элемент
        newNode->prev = Current;            // Указываем в новом элементе предыдущий элемент
    }
}

// Процедура сортировки списка
void listSort(Node **Head) {
    if (*Head == NULL) return;  // В случае пустого списка завершить выполнение процедуры
    //printList(*&Head);
    Node *tempNegative = NULL;  // Указатель на список отрицательных значений
    Node *tempPositive = NULL;  // Указатель на список положительных значений
    Node *Current = *Head;      // Временный указатель
    Node *forDispose = *Head;   // Указатель на старый список

    while (Current->next != NULL) {     // Ищем конец списка
        Current = Current->next;
    }


    while (Current != NULL) {           // Добавляем в список отрицательных значений эти самые значения
        if (Current->data < 0) {
            AddNode(&tempNegative, Current->data);
        }
        Current = Current->prev;
    }

    Current = *Head;                    // Добавляем положительные элементы в соотв. список
    while (Current != NULL) {
        if (Current->data >= 0) {
            AddNode(&tempPositive, Current->data);
        }
        Current = Current->next;
    }

    Current = tempNegative;             // Переставляем указатель на новый список
    if (tempNegative != NULL) {         // В случае если список отрицательных не пустой
        while (Current->next != NULL) { // Ищем его хвост
            Current = Current->next;
        }
        Current->next = tempPositive;   // Примыкаем к этому списку голову положительного списка
        *Head = tempNegative;           // Передаём новый список
    } else {
        *Head = tempPositive;           // Если список отрицательных пуст - просто передаём положительный список
    }

    // Очищаем старый список
    Current = forDispose;
    while(Current != NULL) {
        forDispose = Current->next;
        free(Current);
        Current = forDispose;
    }
}
