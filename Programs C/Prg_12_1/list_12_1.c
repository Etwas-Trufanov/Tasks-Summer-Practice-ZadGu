#include "list_12_1.h"
#include <math.h>
#include <stdlib.h>

// Элемент списка
typedef struct Node {
    float data;           // Данные
    struct Node* next;  // Указатель на следующий узел
} Node;

// Процедура добавления элемента в список
void AddNode(Node **head, float value) {
    Node *newNode = (Node*)malloc(sizeof(Node));    // Объявляем и выделяем элемент
    newNode->data = value;                          // Заполняем его
    newNode->next = NULL;                           // Следующий указатель ставим в NULL

    if (*head == NULL) {                            // Прикрепляем элемент к списку
        *head = newNode;
    } else {
        Node *Current = *head;
        while (Current->next != NULL) {
            Current = Current->next;
        }
        Current->next = newNode;
    }
}

// Функция расчёта синуса модуля суммы списка
float calcListSin(Node *Head) {
    float result = 0.0;         // Переменная результата
    float tempValue = 0.0;      // Переменная суммы
    Node *Cur = Head;           // Указатель
    while (Cur != NULL) {       // Цикл рассчёта суммы
        tempValue += Cur->data;
        Cur = Cur->next;
    }
    result = sinf(fabs(tempValue));     // Расчитываем sin
    return result;                      // Возвращаем результат
}

// Функция очистки списка
void freeList(Node *Head) {
    Node *current = Head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    Head = NULL;
}
