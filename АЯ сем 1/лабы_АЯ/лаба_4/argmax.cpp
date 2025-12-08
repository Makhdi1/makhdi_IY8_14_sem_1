#include "lab05.hpp"

int argmax(const vector<float>& numbers) {
    if (numbers.empty()) {
        return -1;
    }

    int maxIndex = 0; 
    float maxValue = numbers[0];

    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i]; 
            maxIndex = i;         
        }
    }

    return maxIndex;
}