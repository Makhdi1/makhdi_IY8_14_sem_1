#include <iostream>
#include <string>
using namespace std;

void task8() {
    string word = "programming";
    int m = 3, n = 7;
    
    cout << "Word: " << word << endl;
    cout << "m = " << m << ", n = " << n << endl;
    
    if (m >= 0 && n < word.length() && m <= n) {
        string part = word.substr(m, n - m + 1);
        cout << "Part from " << m << " to " << n << ": " << part << endl;
    } else {
        cout << "Invalid indices" << endl;
    }
}