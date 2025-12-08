#include "lab05.hpp"

int argmax(const vector<float>& numbers) {
    // Если вектор пуст, возвращаем -1
    if (numbers.empty()) {
        return -1;
    }

    int maxIndex = 0; // Начинаем с первого элемента
    float maxValue = numbers[0];

    // Проходим по всем элементам, начиная со второго
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i]; // Обновляем максимальное значение
            maxIndex = i;          // Обновляем индекс максимума
        }
    }

    return maxIndex;
}