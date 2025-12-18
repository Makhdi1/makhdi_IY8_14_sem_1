#include "lab04.h"
#include <vector>
#include <limits>

std::pair<float, float> minMax(const std::vector<float>& vec) {
    if (vec.empty()) {
        return std::make_pair(
            std::numeric_limits<float>::max(),
            std::numeric_limits<float>::lowest()
        );
    }
    
    float min_val = vec[0];
    float max_val = vec[0];
    
    for (float num : vec) {
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }
    }
    
    return std::make_pair(min_val, max_val);
}