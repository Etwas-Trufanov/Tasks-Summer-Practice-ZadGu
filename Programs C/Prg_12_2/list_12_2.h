#ifndef LIST_H
#define LIST_H

// Структура узла списка
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;


// Процедура вывода списка
void printList(Node **Head);

// Процедура добавления элемента в список
void AddNode(Node **head, int value);

// Процедура сортировки
void listSort(Node **Head);

#endif
