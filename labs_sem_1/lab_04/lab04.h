#ifndef LAB04_HPP
#define LAB04_HPP

#include <vector>
#include <string>
#include <utility>

float mean(const std::vector<float>& vec);
std::pair<float, float> minMax(const std::vector<float>& vec);
int argmax(const std::vector<float>& vec);
void sort(std::vector<float>& vec);
bool remove_first_negative_element(const std::vector<int>& vec, int& removed_element);
std::string replace(const std::string& str, const std::string& old, const std::string& new_string);
std::vector<std::string> split(const std::string& str, char sep);
std::string join(const std::vector<std::string>& vec, const std::string& sep);

#endif