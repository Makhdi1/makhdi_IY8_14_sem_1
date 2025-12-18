#include "lab06.h"
#include <list>

void reverseNum(std::list<int>& nums){
    for (auto it = nums.begin(); it != nums.end(); ++it){
        int reversed = -(*it);
        nums.insert(it, reversed);
    }
}