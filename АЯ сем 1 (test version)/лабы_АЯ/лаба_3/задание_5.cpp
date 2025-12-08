#include <iostream>
#include <string>
using namespace std;

int main() {
    string city;
    
    cout << "Enter city name: ";
    getline(cin, city);

    int length = city.length();
    
    cout << "City: " << city << endl;
    cout << "Characters count: " << length << endl;
    
    if (length % 2 == 0) {
        cout << "The number of characters is 'Chetniye' " << endl;
    } else {
        cout << "The number of characters is 'Ne chetniye' " << endl;
    }
    
    return 0;
}