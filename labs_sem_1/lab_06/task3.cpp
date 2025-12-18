#include "lab06.h"
#include <string>
#include <vector>

int wordsCounter(const std::string& str){
    if (str.empty()) return 0;
    std::vector<std::string> arr;
    std::string word;
    for (char c : str){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            word += c;
        } else if (!word.empty()) {
            arr.push_back(word);
            word.clear();
        }
    }

    if (!word.empty()){
        arr.push_back(word);
    }

    return arr.size();
}