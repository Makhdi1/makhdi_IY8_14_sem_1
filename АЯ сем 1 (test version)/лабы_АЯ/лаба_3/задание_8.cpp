#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int m, n;
    
    cout << "Enter word: ";
    cin >> word;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;
    
    string result = word.substr(m - 1, n - m + 1);
    
    cout << "Result: " << result << endl;
    
    return 0;
}