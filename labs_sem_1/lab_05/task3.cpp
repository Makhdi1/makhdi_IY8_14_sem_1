#include "lab05.h"

size_t CountTwoness(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        bool hasTwo = false;
        for (unsigned rating : student.Ratings) {
            if (rating == 2) {
                hasTwo = true;
                break;
            }
        }
        if (hasTwo) {
            count++;
        }
    }
    return count;
}