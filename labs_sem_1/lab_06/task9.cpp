#include "lab06.h"
#include <list>
#include <functional>

void Sort(std::list<int>& nums){
    nums.sort(std::greater<int>());
}