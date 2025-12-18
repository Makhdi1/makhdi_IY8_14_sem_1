#include "lab05.h"
#include <set>

std::vector<std::string> GroupsId(const std::vector<Student>& students) {
    std::set<std::string> uniqueGroups;
    for (const auto& student : students) {
        uniqueGroups.insert(student.GroupId);
    }
    return std::vector<std::string>(uniqueGroups.begin(), uniqueGroups.end());
}