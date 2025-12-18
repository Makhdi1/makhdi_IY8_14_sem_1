#include "lab05.h"
#include <algorithm>

void SortByName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.Name < b.Name;
              });
}