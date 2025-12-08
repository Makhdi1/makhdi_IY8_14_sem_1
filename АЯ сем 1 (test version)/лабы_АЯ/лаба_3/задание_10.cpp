#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    
    cout << "Enter sentence: ";
    getline(cin, sentence);
    
    int totalLetters = 0;
    int countA = 0;
    
    for(int i = 0; i < sentence.length(); i++) {
        totalLetters++;
        if(sentence[i] == 'a' || sentence[i] == 'A') {
            countA++;
        }
         
    }
    
    double percentage = 0;
    if(totalLetters > 0) {
        percentage = (countA * 100.0) / totalLetters;
    }
    
    cout << "Percentage of 'a': " << percentage << "%" << endl;
    
    return 0;
}