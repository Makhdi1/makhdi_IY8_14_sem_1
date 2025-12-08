#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size];
    
    cout << "Enter " << size << " array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    
    int arr1[size]; 
    int size1 = 0;
    bool negativeRemoved = false;
    
    for (int i = 0; i < size; i++) {
        if (!negativeRemoved && arr[i] < 0) {
            negativeRemoved = true;
            continue;
        }
        arr1[size1] = arr[i];
        size1++;
    }
    
    if (negativeRemoved) {
        cout << "First negative element removed" << endl;
    } else {
        cout << "No negative elements found" << endl;
    }
    
    cout << "After removing first negative: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // 2. Удаление последнего четного элемента
    int arr2[size]; 
    int size2 = 0;
    int lastEvenIndex = -1;
    
    for (int i = 0; i < size1; i++) {
        if (arr1[i] % 2 == 0) {
            lastEvenIndex = i;
        }
    }
    
    for (int i = 0; i < size1; i++) {
        if (i != lastEvenIndex) {
            arr2[size2] = arr1[i];
            size2++;
        }
    }
    
    if (lastEvenIndex != -1) {
        cout << "Last even element removed" << endl;
    } else {
        cout << "No even elements found" << endl;
    }
    
    cout << "Final array: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    return 0;
}