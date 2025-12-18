#include <iostream>
#include <vector>
using namespace std;

void task4() {
    vector<int> arr = {2, 5, -3, 8, -1, 6, 4, -7, 9, 10};
    
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bool found_negative = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            found_negative = true;
            arr.erase(arr.begin() + i);
            break;
        }
    }
    
    if (found_negative) {
        cout << "After remove first negative: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No negative elements found" << endl;
    }
    
    bool found_even = false;
    int last_even_index = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            last_even_index = i;
            found_even = true;
        }
    }
    
    if (found_even && last_even_index != -1) {
        arr.erase(arr.begin() + last_even_index);
        cout << "After remove last even: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No even elements found" << endl;
    }
}