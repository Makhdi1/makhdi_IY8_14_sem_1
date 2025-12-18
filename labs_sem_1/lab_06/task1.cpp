#include "lab06.h"
#include <vector>

std::vector<int>::iterator find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el){
    for (auto iter = first; iter != last; ++iter){
        if (*iter == el){
            return iter;
        }
    }
    return last;
}