#include <iostream>
#include <string>
using namespace std;

int main() {
    string surname1, surname2;
    
    cout << "Enter first surname: ";
    cin >> surname1;
    
    cout << "Enter second surname: ";
    cin >> surname2;
    
    bool result = surname1.length() > surname2.length();
    
    cout << "Result: " << boolalpha << result << endl;
    
    return 0;
}