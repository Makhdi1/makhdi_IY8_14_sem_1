#include <iostream>
using namespace std;

int main() {
    const int size = 20;
    int arr[size] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
 
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

    cout << "After swapping first 3 and last 3: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}