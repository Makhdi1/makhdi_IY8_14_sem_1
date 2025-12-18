#include "lab06.h"
#include <string>
#include <set>

int diffWordsCounter(const std::string& str){
    std::set<std::string> unique_words;
    std::string word;

    for (char c : str){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            word += c;
        } else if (!word.empty()) {
            unique_words.insert(word);
            word.clear();
        }
    }

    if (!word.empty()){
        unique_words.insert(word);
    }

    return unique_words.size();
}