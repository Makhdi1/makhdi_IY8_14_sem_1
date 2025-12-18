#include "lab07.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::cout << "=== Task 1 ===" << std::endl;

    std::vector<std::string> words = {"apple", "banana", "cherry", "date"};
    saveToFile("words.txt", words);

    std::vector<std::string> loadedWords;
    loadFromFile("words.txt", loadedWords);

    std::cout << "Loaded words:" << std::endl;
    for (const auto& word : loadedWords) {
        std::cout << word << std::endl;
    }

    std::cout << "\n=== Task 2 ===" << std::endl;

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

    std::cout << "\n=== Task 3 ===" << std::endl;

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