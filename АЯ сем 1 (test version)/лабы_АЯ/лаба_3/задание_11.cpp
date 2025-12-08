#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "Can you can a can as a canner can can a can?";
    string new_word = "new_word";
    string result = "";
    
    string word = "";
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ' || sentence[i] == '?') {
            if(word == "can" || word == "Can") {
                result += new_word;
            } else {
                result += word;
            }
            result += sentence[i];
            word = "";
        } else {
            word += sentence[i];
        }
    }
    
    cout << result << endl;
    
    return 0;
}