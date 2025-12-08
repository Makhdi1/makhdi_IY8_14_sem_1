#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <set>
#include <functional>

std::vector<int>::iterator find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el){
    for (auto iter = first; iter != last; ++iter){
        if (*iter == el){
            return iter;
        }
    }
    return last;
}

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el){
    std::sort(first, last);
    for (auto iter = first; iter != last; ++iter){
        if (*iter == el){ 
            return iter;
        }
    }
    return last;
}

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

std::vector<std::string> uniqueWords(const std::string& str){
    std::vector<std::string> result;
    std::string word;
    std::map<std::string, int> word_map;
    
    // Разбиваем на слова и считаем их количество
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

void reverseNum(std::list<int>& nums){
    for (auto it = nums.begin(); it != nums.end(); ++it){
        int reversed = -(*it);
        nums.insert(it, reversed);
    }
}

void plusesDeleter(std::vector<int>& v){
    v.erase(std::remove_if(v.begin(), v.end(), 
                          [](int x) { return x > 0; }), 
            v.end());
}

void Sort(std::list<int>& nums){
    nums.sort(std::greater<int>());
}

int main(){
    // Task 1
    std::cout << "=== Task 1 ===" << std::endl;
    std::vector<int> arr_1 = {1, 2, 3, 4, 5};
    std::vector<int>::iterator iter_1 = find(arr_1.begin(), arr_1.end(), 3);
    if (iter_1 != arr_1.end()) 
        std::cout << "Find(3) = " << std::distance(arr_1.begin(), iter_1) << std::endl;
    
    // Task 2
    std::cout << "\n=== Task 2 ===" << std::endl;
    std::vector<int> arr_2 = {1, 2, 8, 4, 5};
    std::vector<int>::iterator iter_2 = findInSorted(arr_2.begin(), arr_2.end(), 8);
    if (iter_2 != arr_2.end()) 
        std::cout << "Find(8) = " << std::distance(arr_2.begin(), iter_2) << std::endl;
    
    // Task 3
    std::cout << "\n=== Task 3 ===" << std::endl;
    std::string text_1 = "I went home, went to sleep. Woke up and ran";
    int words = wordsCounter(text_1);
    std::cout << "Amount of words from text - \"" << text_1 << "\" - " << words << std::endl;
    
    // Task 4
    std::cout << "\n=== Task 4 ===" << std::endl;
    std::string text_2 = "I went home, went to sleep. Woke up and ran";
    std::map<std::string, int> count_words = wordsMapCounter(text_2);
    for (const auto& c : count_words){
        std::cout << "Words[\"" << c.first << "\"] == " << c.second << std::endl;
    }
    
    // Task 5
    std::cout << "\n=== Task 5 ===" << std::endl;
    std::string text_3 = "Can you can can";
    std::vector<std::string> unique = uniqueWords(text_3);
    std::cout << "Unique words: ";
    for (const auto& word : unique){
        std::cout << "\"" << word << "\" ";
    }
    std::cout << std::endl;
    
    // Task 6
    std::cout << "\n=== Task 6 ===" << std::endl;
    std::string text_4 = "can you can a can";
    int diff_words = diffWordsCounter(text_4);
    std::cout << "Different words count: " << diff_words << std::endl;
    
    // Task 7
    std::cout << "\n=== Task 7 ===" << std::endl;
    std::list<int> nums = {1, 5, 4, -3};
    std::cout << "Before reverseNum: ";
    for (int n : nums) std::cout << n << " ";
    reverseNum(nums);
    std::cout << "\nAfter reverseNum: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;
    
    // Task 8
    std::cout << "\n=== Task 8 ===" << std::endl;
    std::vector<int> v = {1, 0, -8, -9, 0, 10, 23, -7};
    std::cout << "Before plusesDeleter: ";
    for (int n : v) std::cout << n << " ";
    plusesDeleter(v);
    std::cout << "\nAfter plusesDeleter: ";
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;
    
    // Task 9
    std::cout << "\n=== Task 9 ===" << std::endl;
    std::list<int> nums_list = {1, 5, 4, -3};
    std::cout << "Before Sort: ";
    for (int n : nums_list) std::cout << n << " ";
    Sort(nums_list);
    std::cout << "\nAfter Sort: ";
    for (int n : nums_list) std::cout << n << " ";
    std::cout << std::endl;
    
    return 0;
}