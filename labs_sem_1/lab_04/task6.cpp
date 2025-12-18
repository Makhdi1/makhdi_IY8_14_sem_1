#include "lab04.h"
#include <string>

std::string replace(const std::string& str, const std::string& old, const std::string& new_string) {
    std::string result = str;
    size_t pos = 0;
    
    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), new_string);
        pos += new_string.length();
    }
    
    return result;
}