#include "lab05.hpp"

float mean(const vector<float>& numbers) {
     
    if (numbers.empty()) {
        return 0.0f;
    }

    float sum = 0.0f; 
    for (float num : numbers) {
        sum += num;
    }
 
    return sum / numbers.size();
}