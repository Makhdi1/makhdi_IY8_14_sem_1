#include "lab06.h"
#include <string>
#include <map>

std::map<std::string, int> wordsMapCounter(const std::string& text) {
    std::map<std::string, int> word_count;
    std::string word;
    for (char c : text){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            word += c;
        } else if (!word.empty()) {
            word_count[word]++;
            word.clear();
        }
    }
    if (!word.empty()){
        word_count[word]++;
    }
    return word_count;
}