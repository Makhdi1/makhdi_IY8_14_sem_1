#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    
    cout << "Enter word: ";
    cin >> word;
    
    int length = word.length();
    string stars;
    
    for(int i = 0; i < length; i++) {
        stars += "*";
    }
    
    string result = stars + word + stars;
    
    cout << "Result: " << result << endl;
    
    return 0;
}