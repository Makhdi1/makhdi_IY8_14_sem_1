#include <vector>
#include <utility> // для pair
#include <limits>  // для numeric_limits

using namespace std;

// Вычисляет среднее арифметическое элементов вектора
float mean(const vector<float>& numbers);

// Находит минимальный и максимальный элементы вектора
// Возвращает пару (минимум, максимум)
pair<float, float> minMax(const vector<float>& numbers);

// Находит индекс максимального элемента в векторе
// Возвращает -1, если вектор пуст
int argmax(const vector<float>& numbers);