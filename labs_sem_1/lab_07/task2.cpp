#include "lab07.h"
#include <fstream>
#include <iostream>
#include <string>

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& book : data) {
        file << book.Author << "|" << book.Title << "|" << book.Year << std::endl;
    }

    file.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    outData.clear();
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        Book book;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos) {
            book.Author = line.substr(0, pos1);
            book.Title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            book.Year = std::stoi(line.substr(pos2 + 1));
            outData.push_back(book);
        }
    }

    file.close();
}