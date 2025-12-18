#include <iostream>
#include <string>
using namespace std;

void task10() {
    string sentence = "Can you can a can as a canner can can a can?";
    
    cout << "Sentence: " << sentence << endl;
    
    int total_letters = 0;
    int a_count = 0;
    
    for (char c : sentence) {
        if (isalpha(c)) {
            total_letters++;
            if (tolower(c) == 'a') {
                a_count++;
            }
        }
    }
    
    double percentage = 0;
    if (total_letters > 0) {
        percentage = (double)a_count / total_letters * 100;
    }
    
    cout << "Total letters: " << total_letters << endl;
    cout << "Letter 'a' count: " << a_count << endl;
    cout << "Percentage of 'a': " << percentage << "%" << endl;
}