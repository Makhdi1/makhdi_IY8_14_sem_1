#include "lab05.hpp"

float mean(const vector<float>& numbers) {
    // Если вектор пуст, возвращаем 0 (нейтральное значение)
    if (numbers.empty()) {
        return 0.0f;
    }

    float sum = 0.0f;
    // Суммируем все элементы вектора
    for (float num : numbers) {
        sum += num;
    }

    // Возвращаем среднее арифметическое
    return sum / numbers.size();
}