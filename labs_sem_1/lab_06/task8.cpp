#include "lab06.h"
#include <vector>
#include <algorithm>

void plusesDeleter(std::vector<int>& v){
    v.erase(std::remove_if(v.begin(), v.end(), 
                          [](int x) { return x > 0; }), 
            v.end());
}