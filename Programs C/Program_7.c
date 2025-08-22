/*
 * Задание 7
 * 270д
 * Труфанов В. М.
 * Строка, в ней есть пробелы, в каждой такой подстроке есть точка и нужно в этой самой подстроке удалить все первые нули кроме того что стоит перед самой этой точкой
 * типо есть строка 000200.213123 -> 2.213123 или 0000.56456 -> 0.56456
 * (Я так понял, мб это не верно)
 */

#include <locale.h>
#include <stdio.h>

int main() {
    //setlocale(LC_ALL, ".Russian");      // Устанавливаем локаль
    char string[256];                   // Объявляем переменную в которую будем считывать
    puts("Введите строку, содержащую только цифры, точку или пробелы:");
    fgets(string, 256, stdin);          // Считываем строку
    char result[256];                   // Объявляем строку куда будем записывать отформатированную строку
    for (int i = 0; i < 256; i++) result[i] = ' ';      // Удаляем в ней мусор
    int j = 0;                                          // Jитое для цикла
    short hasSymbols = 0;                               // Состояние - были ли после пробела символы?
    short afterPoint = 0;                               // Состояние - идёт ли текущий элемент после точки?
    for (int i = 0; i < 256; i++) {                     // Цикл
        if (string[i] == ' ') {
            hasSymbols = 0;
            afterPoint = 0;
        }
        if (string[i] == '.') {
            afterPoint = 1;
        }
        if ((hasSymbols == 0) && (string[i] != '0') && (afterPoint == 0)) {
            hasSymbols = 1;
        }
        if ((string[i] == '.' || (string[i] == ' '))) {
            result[j] = string[i];
            j++;
        }
        if (afterPoint == 1) {
            result[j] = string[i];
            j++;
        } else
        if ((afterPoint == 0) && (hasSymbols == 0) && (string[i] == '0')) {
            result[j] = string[i];
            j++;
        }
    }
    puts(result);                                                       // Выводим
    return 0;                                                           // Возвращаем 0
}
