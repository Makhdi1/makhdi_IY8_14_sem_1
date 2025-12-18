#include "lab04.h"
#include <vector>

void sort(std::vector<float>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] < vec[j]) {
                float temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}