#include "lab06.h"
#include <string>
#include <vector>
#include <map>

std::vector<std::string> uniqueWords(const std::string& str){
    std::vector<std::string> result;
    std::string word;
    std::map<std::string, int> word_map;

    for (char c : str){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            word += c;
        } else if (!word.empty()) {
            word_map[word]++;
            word.clear();
        }
    }

    if (!word.empty()){
        word_map[word]++;
    }

    for (const auto& pair : word_map){
        if (pair.second == 1){
            result.push_back(pair.first);
        }
    }

    return result;
}