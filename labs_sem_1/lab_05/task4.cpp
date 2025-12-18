#include "lab05.h"

size_t CountExcellent(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        if (student.Ratings.empty()) continue;

        bool allFive = true;
        for (unsigned rating : student.Ratings) {
            if (rating != 5) {
                allFive = false;
                break;
            }
        }
        if (allFive) {
            count++;
        }
    }
    return count;
}