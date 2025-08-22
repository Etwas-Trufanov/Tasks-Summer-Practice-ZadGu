// Реализация модуля проверки степени
#include "check_for_degree.h"

// Функция проверки
// Является ли inputY степенью пятёрки
// Возвращает 1 если да, иначе 0
int CheckVerticles(unsigned inputY) {
    switch (inputY) {
        case 1: return 1;
        case 5: return 1;
        case 25: return 1;
        case 625: return 1;
        case 390625: return 1;
    }
    return 0;
}
