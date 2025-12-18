#include <iostream>
#include <string>
using namespace std;

void task9() {
    string word = "hello";
    int length = word.length();
    
    cout << "Word: " << word << endl;
    cout << "Length: " << length << endl;
    
    string stars;
    for (int i = 0; i < length; i++) {
        stars += "*";
    }
    
    string result = stars + word + stars;
    cout << "Result: " << result << endl;
}