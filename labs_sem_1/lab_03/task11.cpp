#include <iostream>
#include <string>
using namespace std;

void task11() {
    string sentence = "Can you can a can as a canner can can a can?";
    string new_word = "new_word";

    cout << "Original: " << sentence << endl;

    string result = sentence;
    size_t pos = 0;

    while ((pos = result.find("can", pos)) != string::npos) {
        if ((pos == 0 || !isalpha(result[pos-1])) &&
            (pos+3 == result.length() || !isalpha(result[pos+3]))) {
            result.replace(pos, 3, new_word);
            pos += new_word.length();
            } else {
                pos += 3;
            }
    }

    cout << "After replace: " << result << endl;
}