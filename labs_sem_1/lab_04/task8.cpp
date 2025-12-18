#include "lab04.h"
#include <vector>
#include <string>

std::string join(const std::vector<std::string>& vec, const std::string& sep) {
    std::string result;
    
    for (int i = 0; i < vec.size(); i++) {
        result += vec[i];
        if (i != vec.size() - 1) {
            result += sep;
        }
    }
    
    return result;
}