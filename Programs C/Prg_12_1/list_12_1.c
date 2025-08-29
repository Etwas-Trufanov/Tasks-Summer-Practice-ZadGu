#include "list_12_1.h"
#include <math.h>
#include <stdlib.h>

// Элемент списка
typedef struct Node {
    float data;
    struct Node *next;
} Node;

// Функция добавления элемента в список
Node* AddNode(Node *head, float value) {
	Node *tmp = malloc(sizeof(Node));
	tmp->data = value;
	tmp->next = NULL;
	if (head == NULL) {
		return tmp;
	}
	Node *cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
	return head;
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
