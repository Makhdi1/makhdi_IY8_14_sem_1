#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

// === Tusk 1 ===

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

// === Tusk 2 ===

struct Book {
    std::string Author;
    std::string Title;
    int Year;
};

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

// Функция загрузки массива книг из файла
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

// === Tusk 3 ===

enum Score {
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student {
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;

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

int main() {
    std::cout << "=== Tusk 1 ===" << std::endl;
    
    std::vector<std::string> words = {"apple", "banana", "cherry", "date"};
    saveToFile("words.txt", words);
    
    std::vector<std::string> loadedWords;
    loadFromFile("words.txt", loadedWords);
    
    std::cout << "Loaded words:" << std::endl;
    for (const auto& word : loadedWords) {
        std::cout << word << std::endl;
    }
    
    std::cout << "\n=== Tusk 2 ===" << std::endl;
    
    std::vector<Book> books = {
        {"J.K. Rowling", "Harry Potter and the Philosopher's Stone", 1997},
        {"George Orwell", "1984", 1949},
        {"J.R.R. Tolkien", "The Lord of the Rings", 1954}
    };
    
    saveToFile("books.txt", books);
    
    std::vector<Book> loadedBooks;
    loadFromFile("books.txt", loadedBooks);
    
    std::cout << "Loaded books:" << std::endl;
    for (const auto& book : loadedBooks) {
        std::cout << book.Author << " - " << book.Title << " (" << book.Year << ")" << std::endl;
    }
    
    std::cout << "\n=== Tusk 3 ===" << std::endl;
    
    Groups groups;
    
    std::vector<Student> group1;
    Student student1;
    student1.Name = "Ivan Ivanov";
    student1.Year = 2;
    student1.RecordBook = {{"Math", Good}, {"Physics", Excellent}, {"Programming", Excellent}};
    group1.push_back(student1);
    
    Student student2;
    student2.Name = "Petr Petrov";
    student2.Year = 2;
    student2.RecordBook = {{"Math", Satisfactorily}, {"Physics", Good}, {"Programming", Good}};
    group1.push_back(student2);
    
    groups["CS-101"] = group1;
    
    std::vector<Student> group2;
    Student student3;
    student3.Name = "Anna Sidorova";
    student3.Year = 3;
    student3.RecordBook = {{"Math", Excellent}, {"Physics", Excellent}, {"Programming", Excellent}};
    group2.push_back(student3);
    
    groups["IT-202"] = group2;
    
    saveToFile("students.txt", groups);
    
    Groups loadedGroups;
    loadFromFile("students.txt", loadedGroups);
    
    std::cout << "Loaded groups:" << std::endl;
    for (const auto& group : loadedGroups) {
        std::cout << "\nGroup: " << group.first << std::endl;
        for (const auto& student : group.second) {
            std::cout << "  Student: " << student.Name << " (Year: " << student.Year << ")" << std::endl;
            std::cout << "    Grades: ";
            for (const auto& record : student.RecordBook) {
                std::cout << record.first << ": " << record.second << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}