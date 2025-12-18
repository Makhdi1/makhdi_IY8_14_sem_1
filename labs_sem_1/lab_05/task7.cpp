#include "lab05.h"

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