package io.github.etwastrufanov.calc_with_precision;

// Главный класс модуля (модели)
public class MainModel {
    // Функция для вычисления i-го слагаемого
    private static double func(int i) {
        return 1.0 / (i * (i + 1.0));
    }

    // Главная функция модуля, рассчитывает сумму ряда с заданной точностью
    static double calc(double precision) {
        double value = 0.0;  // накопленная сумма
        int step = 1;        // текущий шаг

        double term = func(step); // первое слагаемое
        while (Math.abs(term) >= precision) {
            value += term;
            step++;
            term = func(step);    // вычисляем следующее слагаемое
            if (step > 1000000) break; // защита от бесконечного цикла
        }
        return value;
    }
}
