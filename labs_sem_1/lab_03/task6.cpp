#include <iostream>
#include <string>
using namespace std;

void task6() {
    string surname1 = "Ivanov";
    string surname2 = "Petrov";
    
    cout << "Surname 1: " << surname1 << endl;
    cout << "Surname 2: " << surname2 << endl;
    cout << "Length 1: " << surname1.length() << endl;
    cout << "Length 2: " << surname2.length() << endl;
    
    bool result = surname1.length() > surname2.length();
    cout << "First is longer: " << (result ? "true" : "false") << endl;
}