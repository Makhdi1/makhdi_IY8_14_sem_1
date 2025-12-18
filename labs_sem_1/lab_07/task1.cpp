#include "lab07.h"
#include <fstream>
#include <iostream>

void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& word : data) {
        file << word << std::endl;
    }

    file.close();
}

void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    outData.clear();
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            outData.push_back(line);
        }
    }

    file.close();
}