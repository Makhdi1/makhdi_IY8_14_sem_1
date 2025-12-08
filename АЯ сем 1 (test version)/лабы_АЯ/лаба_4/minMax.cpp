#include "lab05.hpp"

pair<float, float> minMax(const vector<float>& numbers) {
    // Если вектор пуст, возвращаем специальные значения
    if (numbers.empty()) {
        return {
            numeric_limits<float>::lowest(),    // Минимум = самое большое число
            numeric_limits<float>::max()  // Максимум = самое маленькое число
        };
    }

    // Начинаем с первого элемента
    float min = numbers[0];
    float max = numbers[0];

    // Проходим по всем элементам вектора
    for (float num : numbers) {
        if (num < min) {
            min = num; // Нашли новый минимум
        }
        if (num > max) {
            max = num; // Нашли новый максимум
        }
    }

    return {min, max};
}