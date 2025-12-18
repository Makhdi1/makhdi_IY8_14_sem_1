#include "lab04.h"
#include <vector>

bool remove_first_negative_element(const std::vector<int>& vec, int& removed_element) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            removed_element = vec[i];
            return true;
        }
    }
    
    removed_element = 0;
    return false;
}