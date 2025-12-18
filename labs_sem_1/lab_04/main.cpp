#include "lab04.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "Task 1 - Mean:" << std::endl;
    std::vector<float> numbers = {1.5, 2.5, 3.5, 4.5, 5.5};
    float avg = mean(numbers);
    std::cout << "Mean: " << avg << std::endl;

    std::cout << "\nTask 2 - MinMax:" << std::endl;
    std::pair<float, float> min_max = minMax(numbers);
    std::cout << "Min: " << min_max.first << ", Max: " << min_max.second << std::endl;

    std::cout << "\nTask 3 - Argmax:" << std::endl;
    int max_index = argmax(numbers);
    std::cout << "Index of max: " << max_index << std::endl;

    std::cout << "\nTask 4 - Sort:" << std::endl;
    std::vector<float> numbers_copy = numbers;
    sort(numbers_copy);
    std::cout << "Sorted: ";
    for (float num : numbers_copy) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTask 5 - Remove first negative:" << std::endl;
    std::vector<int> numbers_int = {2, 5, -3, 8, -1, 6};
    int removed;
    bool success = remove_first_negative_element(numbers_int, removed);
    std::cout << "Success: " << (success ? "true" : "false") << std::endl;
    std::cout << "Removed element: " << removed << std::endl;

    std::cout << "\nTask 6 - Replace:" << std::endl;
    std::string text = "Can you can a can as a canner can can a can?";
    std::string new_text = replace(text, "can", "new_word");
    std::cout << "Original: " << text << std::endl;
    std::cout << "Replaced: " << new_text << std::endl;

    std::cout << "\nTask 7 - Split:" << std::endl;
    std::vector<std::string> words = split(text, ' ');
    std::cout << "Split result: ";
    for (const std::string& word : words) {
        std::cout << "[" << word << "] ";
    }
    std::cout << std::endl;

    std::cout << "\nTask 8 - Join:" << std::endl;
    std::string joined = join(words, " ");
    std::cout << "Joined: " << joined << std::endl;

    return 0;
}