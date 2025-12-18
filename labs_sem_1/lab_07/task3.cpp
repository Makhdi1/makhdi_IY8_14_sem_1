#include "lab07.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void saveToFile(const std::string& filename, const Groups& groups) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& group : groups) {
        file << "[" << group.first << "]" << std::endl;

        for (const auto& student : group.second) {
            file << student.Name << ";" << student.Year;

            for (const auto& record : student.RecordBook) {
                file << ";" << record.first << ":" << record.second;
            }

            file << std::endl;
        }

        file << std::endl;
    }

    file.close();
}

void loadFromFile(const std::string& filename, Groups& outGroups) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    outGroups.clear();
    std::string line;
    std::string currentGroup;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line.front() == '[' && line.back() == ']') {
            currentGroup = line.substr(1, line.size() - 2);
            outGroups[currentGroup] = std::vector<Student>();
        } else if (!currentGroup.empty()) {
            std::istringstream iss(line);
            std::string token;
            Student student;

            std::getline(iss, token, ';');
            student.Name = token;

            std::getline(iss, token, ';');
            student.Year = std::stoi(token);

            while (std::getline(iss, token, ';')) {
                size_t colonPos = token.find(':');
                if (colonPos != std::string::npos) {
                    std::string subject = token.substr(0, colonPos);
                    Score score = static_cast<Score>(std::stoi(token.substr(colonPos + 1)));
                    student.RecordBook[subject] = score;
                }
            }

            outGroups[currentGroup].push_back(student);
        }
    }

    file.close();
}