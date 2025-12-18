#include "lab05.h"
#include <iostream>
#include <vector>

int main() {
    Student student1 = {"John", "IBM1-21", {5, 5, 5}, {"Physics", "Math", "Programming"}};
    Student student2 = {"Alice", "IY6-32", {5, 2, 5}, {"Physics", "Math", "Programming"}};
    Student student3 = {"Bob", "MT2-15", {3, 5, 4}, {"Physics", "Math", "Programming"}};
    Student student4 = {"Emma", "IBM1-21", {5, 5, 5, 5}, {"Math", "Physics", "Chemistry", "English"}};

    std::vector<Student> students = {student1, student2, student3, student4};

    std::cout << "Task 1 - SortByName:" << std::endl;
    std::vector<Student> students_copy = students;
    SortByName(students_copy);
    std::cout << "Sorted by name: ";
    for (const auto& student : students_copy) {
        std::cout << student.Name << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTask 2 - SortByRating:" << std::endl;
    students_copy = students;
    SortByRating(students_copy);
    std::cout << "Sorted by rating: ";
    for (const auto& student : students_copy) {
        double avg = 0;
        if (!student.Ratings.empty()) {
            for (unsigned rating : student.Ratings) {
                avg += rating;
            }
            avg /= student.Ratings.size();
        }
        std::cout << student.Name << "(" << avg << ") ";
    }
    std::cout << std::endl;

    std::cout << "\nTask 3 - CountTwoness:" << std::endl;
    size_t twoness = CountTwoness(students);
    std::cout << "Students with grade 2: " << twoness << std::endl;

    std::cout << "\nTask 4 - CountExcellent:" << std::endl;
    size_t excellent = CountExcellent(students);
    std::cout << "Excellent students: " << excellent << std::endl;

    std::cout << "\nTask 5 - VectorMathExcellent:" << std::endl;
    std::vector<Student> math_excellent = VectorMathExcellent(students);
    std::cout << "Students with excellent Math: " << math_excellent.size() << std::endl;
    for (const auto& student : math_excellent) {
        std::cout << student.Name << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTask 6 - GroupsId:" << std::endl;
    std::vector<std::string> group_ids = GroupsId(students);
    std::cout << "Group IDs: ";
    for (const auto& id : group_ids) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTask 7 - Groups:" << std::endl;
    std::vector<Group> groups = Groups(students);
    std::cout << "Number of groups: " << groups.size() << std::endl;
    for (const auto& group : groups) {
        std::cout << "Group " << group.Id << ": " << group.Students.size() << " students" << std::endl;
    }

    return 0;
}