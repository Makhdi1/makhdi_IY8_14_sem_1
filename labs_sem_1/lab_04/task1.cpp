#include "lab04.h"
#include <vector>

float mean(const std::vector<float>& vec) {
    if (vec.empty()) {
        return 0.0f;
    }
    
    float sum = 0.0f;
    for (float num : vec) {
        sum += num;
    }
    
    return sum / vec.size();
}