#include <iostream>
#include <vector>
#include <limits>
// #include "lab05.hpp"


using namespace std;

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

int main() {
    vector<float> data = {1.5f, 3.2f, 2.8f, 4.1f, 0.9f};

    cout << "Mean: " << mean(data) << endl;

    auto [min, max] = minMax(data);
    cout << "Min: " << min << ", Max: " << max << endl;

    cout << "Argmax: " << argmax(data) << endl;

    vector<float> empty;
    cout << "Empty vector mean: " << mean(empty) << endl;
    auto [min2, max2] = minMax(empty);
    cout << "Empty vector min: " << min2 << ", max: " << max2 << endl;
    cout << "Empty vector argmax: " << argmax(empty) << endl;

    return 0;
}