#ifndef LAB06_H
#define LAB06_H

#include <vector>
#include <list>
#include <string>
#include <map>

std::vector<int>::iterator find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el);
std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el);
int wordsCounter(const std::string& str);
std::map<std::string, int> wordsMapCounter(const std::string& text);
std::vector<std::string> uniqueWords(const std::string& str);
int diffWordsCounter(const std::string& str);
void reverseNum(std::list<int>& nums);
void plusesDeleter(std::vector<int>& v);
void Sort(std::list<int>& nums);

#endif