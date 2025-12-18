#include <iostream>
#include <vector>
using namespace std;

void task1() {
    vector<int> arr = {2, 4, 6, 8, 10};
    int size = arr.size();
    int a = 3;

    cout << "Massiv: ";
    for (auto& num:arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "After * on 2: ";
    for (auto& num:arr) {
        cout << num*2 << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] - a;
    }

    cout << "After - a = " << a << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int firstElement = arr[0];
    float newarr[size];
    for (int i = 0; i < size; i++){
        newarr[i] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        newarr[i] = newarr[i] / firstElement;
    }

    cout << "After / on first element (" << firstElement << "): ";
    for (int i = 0; i < size; i++) {
        cout << newarr[i] << " ";
    }
    cout << endl;
}