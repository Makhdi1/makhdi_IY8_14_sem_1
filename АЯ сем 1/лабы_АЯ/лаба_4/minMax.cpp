#include "lab05.hpp"

pair<float, float> minMax(const vector<float>& numbers) { 
    if (numbers.empty()) {
        return {
            numeric_limits<float>::lowest(),    
            numeric_limits<float>::max()   //  
        };
    }

     
    float min = numbers[0];
    float max = numbers[0];

     
    for (float num : numbers) {
        if (num < min) {
            min = num; 
        }
        if (num > max) {
            max = num; // 
        }
    }

    return {min, max};
}