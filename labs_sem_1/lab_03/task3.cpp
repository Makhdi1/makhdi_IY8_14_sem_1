#include <iostream>
#include <vector>
using namespace std;

void task3() {
    const int size = 20;
    vector<int> arr(size);
    
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 3 + i];
        arr[size - 3 + i] = temp;
    }
    
    cout << "After swap: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}