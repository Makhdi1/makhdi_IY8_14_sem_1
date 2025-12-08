#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <numeric>

struct Student
{
    std::string Name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
};

struct Group
{
    std::string Id;
    std::vector<Student> Students;
};

void SortByName(std::vector<Student>&);

void SortByRating(std::vector<Student>&);

size_t CountTwoness(const std::vector<Student>&);

size_t CountExcellent(const std::vector<Student>&);

std::vector<Student> VectorMathExcellent(const std::vector<Student>&);

std::vector<std::string> GroupsId(const std::vector<Student>&);

std::vector<Group> Groups(const std::vector<Student>&);

// Task 1
void SortByName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.Name < b.Name;
              });
}

// Task 2
void SortByRating(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  if (a.Ratings.empty() && b.Ratings.empty()) return false;
                  if (a.Ratings.empty()) return true;
                  if (b.Ratings.empty()) return false;

                  double avgA = std::accumulate(a.Ratings.begin(), a.Ratings.end(), 0.0) / a.Ratings.size();
                  double avgB = std::accumulate(b.Ratings.begin(), b.Ratings.end(), 0.0) / b.Ratings.size();
                  return avgA > avgB;
              });
}

// Task 3
size_t CountTwoness(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        bool hasBadGrade = false;
        for (unsigned rating : student.Ratings) {
            if (rating == 2) {
                hasBadGrade = true;
            }
        }
        if (hasBadGrade) {
            count++;
            break;
        }
    }
    return count;
}

// Task 4
size_t CountExcellent(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        if (student.Ratings.empty()) continue;

        bool allExcellent = true;
        for (unsigned rating : student.Ratings) {
            if (rating != 5) {
                allExcellent = false;
                break;
            }
        }
        if (allExcellent) {
            count++;
        }
    }
    return count;
}

// Task 5
std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
    std::vector<Student> result;
    for (const auto& student : students) {
        for (size_t i = 0; i < student.Subjects.size() && i < student.Ratings.size(); ++i) {
            if (student.Subjects[i] == "Math" && student.Ratings[i] == 5) {
                result.push_back(student);
                break;
            }
        }
    }
    return result;
}

// Task 6
std::vector<std::string> GroupsId(const std::vector<Student>& students) {
    std::set<std::string> uniqueGroups;
    for (const auto& student : students) {
        uniqueGroups.insert(student.GroupId);
    }
    return std::vector<std::string>(uniqueGroups.begin(), uniqueGroups.end());
}

// Task 7
std::vector<Group> Groups(const std::vector<Student>& students) {
    std::vector<Group> result;
    std::vector<std::string> groupIds = GroupsId(students);

    for (const auto& groupId : groupIds) {
        Group group;
        group.Id = groupId;

        for (const auto& student : students) {
            if (student.GroupId == groupId) {
                group.Students.push_back(student);
            }
        }

        result.push_back(group);
    }
    return result;
}

int main() {
    Student student1 = {"John", "IBM1-21", {5, 5, 5}, {"Physics", "Math", "Programming"}};
    Student student2 = {"Alice", "IY6-32", {5, 2, 5}, {"Physics", "Math", "Programming"}};
    Student student3 = {"Bob", "MT2-15", {3, 5, 4}, {"Physics", "Math", "Programming"}};
    std::vector<Student> students = {student1, student2, student3};
    
    SortByName(students);
    SortByRating(students);
    CountTwoness(students);
    CountExcellent(students);
    VectorMathExcellent(students);
    Groups(students);
    GroupsId(students);
}