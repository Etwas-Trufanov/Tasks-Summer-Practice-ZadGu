#include "list_12_2.h"
#include <stdlib.h>
#include <stdio.h>


void PrintList(Node *head) {
    Node *Current = head;
    printf("=== Out ===\n");
    if (head == NULL) {
        printf("List is clear\n");
        return;
    }
    while (Current != NULL) {
        printf("%i ", Current->data);
        Current = Current->next;
    }
    printf("\n");
}

// Реализация функции добавления ноды в конец списка
Node* AddNode(Node *head, int data) {
	Node *tmp = malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
	if (head == NULL) {
	    tmp->prev = NULL;
		return tmp;
	}
	Node *cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	tmp->prev = cur;
	cur->next = tmp;
	return head;
}

// Процедура сортировки
Node* SortList(Node *head) {
    // Если список пуст
    if (head == NULL) {
        return NULL;
    }


    // Головы списков положительных и отрицательных элементов
    Node *negative_head = NULL;
    Node *positive_head = NULL;
    // Текущий элемент
    Node *current = head;

    // Ищем все положительные элементы
    while (current != NULL) {
        if (current->data >= 0) {
            positive_head = AddNode(positive_head, current->data);
        }
        current = current->next;
    }

    // Ищем хвост
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Ищем все отрицательные элементы
    while (current != NULL) {
        if (current->data < 0) {
            negative_head = AddNode(negative_head, current->data);
        }
        current = current->prev;
    }


    // Ищем хвост списка отрицательных чисел
    current = negative_head;
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }

        // Цепляем к нему положительные числа
        current->next = positive_head;
        return negative_head;

    } else
    // Если список отрицательных пуст:
    return positive_head;
}
