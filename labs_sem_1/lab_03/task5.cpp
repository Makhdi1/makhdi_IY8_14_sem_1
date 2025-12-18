#include <iostream>
#include <string>
using namespace std;

void task5() {
    string city = "Moscow";
    
    cout << "City: " << city << endl;
    cout << "Length: " << city.length() << endl;
    
    if (city.length() % 2 == 0) {
        cout << "Length is even" << endl;
    } else {
        cout << "Length is odd" << endl;
    }
}