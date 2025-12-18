#include "lab04.h"
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& str, char sep) {
    std::vector<std::string> result;
    std::string current;
    
    bool all_sep = true;
    for (char c : str) {
        if (c != sep) {
            all_sep = false;
        }
    }
    
    if (all_sep) {
        return result;
    }
    
    for (char c : str) {
        if (c == sep) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    
    if (!current.empty()) {
        result.push_back(current);
    }
    
    return result;
}