#ifndef LIST_H
#define LIST_H

// Структура узла списка
typedef struct Node Node;

// Процедура добавления элемента в список
void AddNode(Node **head, float value);

// Функция расчёта синуса модуля суммы списка
float calcListSin(Node *Head);

// Процедура очистки
void freeList(Node *Head);
#endif
