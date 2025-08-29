#ifndef LIST_H
#define LIST_H

// Структура узла списка
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;


// Процедура вывода списка
void PrintList(Node *head);

// Функция добавления элемента в список
Node* AddNode(Node *head, int data);

// Процедура сортировки
Node* SortList(Node *head);

#endif
