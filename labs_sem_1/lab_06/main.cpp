#include "lab06.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

int main(){
    std::cout << "=== Task 1 ===" << std::endl;
    std::vector<int> arr_1 = {1, 2, 3, 4, 5};
    std::vector<int>::iterator iter_1 = find(arr_1.begin(), arr_1.end(), 3);
    if (iter_1 != arr_1.end())
        std::cout << "Find(3) = " << std::distance(arr_1.begin(), iter_1) << std::endl;

    std::cout << "\n=== Task 2 ===" << std::endl;
    std::vector<int> arr_2 = {1, 2, 8, 4, 5};
    std::vector<int>::iterator iter_2 = findInSorted(arr_2.begin(), arr_2.end(), 8);
    if (iter_2 != arr_2.end())
        std::cout << "Find(8) = " << std::distance(arr_2.begin(), iter_2) << std::endl;

    std::cout << "\n=== Task 3 ===" << std::endl;
    std::string text_1 = "I went home, went to sleep. Woke up and ran";
    int words = wordsCounter(text_1);
    std::cout << "Amount of words from text - \"" << text_1 << "\" - " << words << std::endl;

    std::cout << "\n=== Task 4 ===" << std::endl;
    std::string text_2 = "I went home, went to sleep. Woke up and ran";
    std::map<std::string, int> count_words = wordsMapCounter(text_2);
    for (const auto& c : count_words){
        std::cout << "Words[\"" << c.first << "\"] == " << c.second << std::endl;
    }

    std::cout << "\n=== Task 5 ===" << std::endl;
    std::string text_3 = "Can you can can";
    std::vector<std::string> unique = uniqueWords(text_3);
    std::cout << "Unique words: ";
    for (const auto& word : unique){
        std::cout << "\"" << word << "\" ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Task 6 ===" << std::endl;
    std::string text_4 = "can you can a can";
    int diff_words = diffWordsCounter(text_4);
    std::cout << "Different words count: " << diff_words << std::endl;

    std::cout << "\n=== Task 7 ===" << std::endl;
    std::list<int> nums = {1, 5, 4, -3};
    std::cout << "Before reverseNum: ";
    for (int n : nums) std::cout << n << " ";
    reverseNum(nums);
    std::cout << "\nAfter reverseNum: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "\n=== Task 8 ===" << std::endl;
    std::vector<int> v = {1, 0, -8, -9, 0, 10, 23, -7};
    std::cout << "Before plusesDeleter: ";
    for (int n : v) std::cout << n << " ";
    plusesDeleter(v);
    std::cout << "\nAfter plusesDeleter: ";
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;

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