#include "lab04.h"
#include <vector>

int argmax(const std::vector<float>& vec) {
    if (vec.empty()) {
        return -1;
    }
    
    int max_index = 0;
    float max_val = vec[0];
    
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max_val) {
            max_val = vec[i];
            max_index = i;
        }
    }
    
    return max_index;
}