#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

int list_type = 1;
Node* first = nullptr;
int list_size = 0;

void make_empty() {
    if (first == nullptr) return;

    Node* cur = first;
    Node* next_node;

    if (list_type == 3 || list_type == 4) {
        for (int i = 0; i < list_size; i++) {
            next_node = cur->next;
            delete cur;
            cur = next_node;
        }
    } else {
        while (cur != nullptr) {
            next_node = cur->next;
            delete cur;
            cur = next_node;
        }
    }

    first = nullptr;
    list_size = 0;
}

void add_node(int val) {
    Node* new_node = new Node(val);

    if (first == nullptr) {
        first = new_node;
        if (list_type == 3 || list_type == 4) {
            new_node->next = new_node;
            if (list_type == 4) {
                new_node->prev = new_node;
            }
        }
    } else {
        Node* cur = first;

        if (list_type == 3 || list_type == 4) {
            while (cur->next != first) {
                cur = cur->next;
            }
            cur->next = new_node;
            new_node->next = first;
            if (list_type == 4) {
                new_node->prev = cur;
                first->prev = new_node;
            }
        } else {
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new_node;
            if (list_type == 2 || list_type == 4) {
                new_node->prev = cur;
            }
        }
    }

    list_size++;
}

void show_list() {
    if (first == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    std::cout << "List: ";
    Node* cur = first;

    if (list_type == 3 || list_type == 4) {
        for (int i = 0; i < list_size; i++) {
            std::cout << cur->value;
            if (i < list_size - 1) std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << " -> back to start";
    } else {
        while (cur != nullptr) {
            std::cout << cur->value;
            if (cur->next != nullptr) std::cout << " -> ";
            cur = cur->next;
        }
    }

    std::cout << std::endl;
}

std::vector<int> find_value(int val) {
    std::vector<int> positions;

    if (first == nullptr) return positions;

    Node* cur = first;
    int pos = 0;

    if (list_type == 3 || list_type == 4) {
        for (int i = 0; i < list_size; i++) {
            if (cur->value == val) {
                positions.push_back(pos);
            }
            cur = cur->next;
            pos++;
        }
    } else {
        while (cur != nullptr) {
            if (cur->value == val) {
                positions.push_back(pos);
            }
            cur = cur->next;
            pos++;
        }
    }

    return positions;
}

bool delete_one(int val) {
    if (first == nullptr) return false;

    Node* cur = first;
    Node* prev = nullptr;

    if (list_type == 3 || list_type == 4) {
        for (int i = 0; i < list_size; i++) {
            if (cur->value == val) {
                if (list_size == 1) {
                    delete cur;
                    first = nullptr;
                } else {
                    if (cur == first) {
                        first = cur->next;
                    }

                    if (cur->next != nullptr) {
                        cur->next->prev = cur->prev;
                    }
                    if (cur->prev != nullptr) {
                        cur->prev->next = cur->next;
                    }

                    delete cur;
                }

                list_size--;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
    } else {
        while (cur != nullptr) {
            if (cur->value == val) {
                if (prev == nullptr) {
                    first = cur->next;
                    if (first != nullptr && (list_type == 2 || list_type == 4)) {
                        first->prev = nullptr;
                    }
                } else {
                    prev->next = cur->next;
                    if (cur->next != nullptr && (list_type == 2 || list_type == 4)) {
                        cur->next->prev = prev;
                    }
                }

                delete cur;
                list_size--;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    return false;
}

int delete_all(int val) {
    int count = 0;
    while (delete_one(val)) {
        count++;
    }
    return count;
}

bool save_to_file(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    if (list_type == 1) file << ">";
    else if (list_type == 2) file << "<>";
    else if (list_type == 3) file << ">0";
    else if (list_type == 4) file << "<>0";
    file << std::endl;

    if (first != nullptr) {
        Node* cur = first;

        if (list_type == 3 || list_type == 4) {
            for (int i = 0; i < list_size; i++) {
                file << cur->value;
                if (i < list_size - 1) file << ",";
                cur = cur->next;
            }
        } else {
            while (cur != nullptr) {
                file << cur->value;
                if (cur->next != nullptr) file << ",";
                cur = cur->next;
            }
        }
    }

    file.close();
    return true;
}

bool load_from_file(const std::string& filename) {
    if (first != nullptr) {
        std::cout << "List already exists!" << std::endl;
        return false;
    }

    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string type_str;
    std::getline(file, type_str);

    if (type_str == ">") list_type = 1;
    else if (type_str == "<>") list_type = 2;
    else if (type_str == ">0") list_type = 3;
    else if (type_str == "<>0") list_type = 4;
    else return false;

    std::string data;
    if (std::getline(file, data)) {
        size_t start = 0;
        size_t end = data.find(',');

        while (end != std::string::npos) {
            std::string num = data.substr(start, end - start);
            if (!num.empty()) {
                add_node(std::stoi(num));
            }
            start = end + 1;
            end = data.find(',', start);
        }

        std::string last_num = data.substr(start);
        if (!last_num.empty()) {
            add_node(std::stoi(last_num));
        }
    }

    file.close();
    return true;
}

void show_menu() {
    std::cout << "\n=== MENU ===" << std::endl;
    std::cout << "1. Add element" << std::endl;
    std::cout << "2. Show list" << std::endl;
    std::cout << "3. Find element" << std::endl;
    std::cout << "4. Delete first occurrence" << std::endl;
    std::cout << "5. Delete all occurrences" << std::endl;
    std::cout << "6. Clear list" << std::endl;
    std::cout << "7. Save to file" << std::endl;
    std::cout << "8. Load from file" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choice: ";
}

int main(int argc, char* argv[]) {
    // Обработка аргументов командной строки (если они есть)
    if (argc > 1) {
        int element_count = 0;
        std::vector<int> elements;

        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-t") == 0) {
                if (i + 1 < argc) {
                    list_type = atoi(argv[++i]);
                    if (list_type < 1 || list_type > 4) {
                        std::cout << "Wrong type!" << std::endl;
                        return 1;
                    }
                }
            } else if (strcmp(argv[i], "-c") == 0) {
                if (i + 1 < argc) {
                    element_count = atoi(argv[++i]);
                }
            } else if (strcmp(argv[i], "-e") == 0) {
                if (i + 1 < argc) {
                    char* elements_str = argv[++i];
                    char* token = strtok(elements_str, ",");
                    while (token != nullptr) {
                        elements.push_back(atoi(token));
                        token = strtok(nullptr, ",");
                    }
                }
            } else {
                std::cout << "Wrong parameter: " << argv[i] << std::endl;
                return 1;
            }
        }

        if (element_count > 0 && element_count != elements.size()) {
            std::cout << "Wrong element count!" << std::endl;
            return 1;
        }

        for (int elem : elements) {
            add_node(elem);
        }
    }


    int choice;
    do {
        show_menu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                std::cout << "Enter number: ";
                std::cin >> val;
                add_node(val);
                break;
            }
            case 2:
                show_list();
                break;
            case 3: {
                int val;
                std::cout << "Enter number to find: ";
                std::cin >> val;
                std::vector<int> pos = find_value(val);
                if (pos.empty()) {
                    std::cout << "Not found" << std::endl;
                } else {
                    std::cout << "Found at positions: ";
                    for (int p : pos) {
                        std::cout << p << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            }
            case 4: {
                int val;
                std::cout << "Enter number to delete: ";
                std::cin >> val;
                if (delete_one(val)) {
                    std::cout << "Deleted" << std::endl;
                } else {
                    std::cout << "Not found" << std::endl;
                }
                break;
            }
            case 5: {
                int val;
                std::cout << "Enter number to delete all: ";
                std::cin >> val;
                int deleted = delete_all(val);
                std::cout << "Deleted " << deleted << " times" << std::endl;
                break;
            }
            case 6:
                make_empty();
                std::cout << "List cleared" << std::endl;
                break;
            case 7: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                if (save_to_file(filename)) {
                    std::cout << "Saved" << std::endl;
                } else {
                    std::cout << "Error saving" << std::endl;
                }
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                if (load_from_file(filename)) {
                    std::cout << "Loaded" << std::endl;
                } else {
                    std::cout << "Error loading" << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Wrong choice!" << std::endl;
        }
    } while (choice != 0);

    make_empty();
    return 0;
}