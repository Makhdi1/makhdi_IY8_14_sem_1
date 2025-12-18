#include "lab06.h"
#include <vector>
#include <algorithm>

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el){
    std::sort(first, last);
    for (auto iter = first; iter != last; ++iter){
        if (*iter == el){
            return iter;
        }
    }
    return last;
}