#include "lab05.h"

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
    std::vector<Student> result;
    for (const auto& student : students) {
        bool hasMathExcellent = false;
        for (size_t i = 0; i < student.Subjects.size() && i < student.Ratings.size(); ++i) {
            if (student.Subjects[i] == "Math" && student.Ratings[i] == 5) {
                hasMathExcellent = true;
                break;
            }
        }
        if (hasMathExcellent) {
            result.push_back(student);
        }
    }
    return result;
}