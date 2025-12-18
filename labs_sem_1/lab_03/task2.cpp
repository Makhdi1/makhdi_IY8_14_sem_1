#include <iostream>
#include <vector>
using namespace std;

void task2() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = arr.size();
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum of all elements: " << sum << endl;
    
    int sum_squares = 0;
    for (int i = 0; i < size; i++) {
        sum_squares += arr[i] * arr[i];
    }
    cout << "Sum of squares: " << sum_squares << endl;
    
    int sum_six = 0;
    for (int i = 0; i < 6 && i < size; i++) {
        sum_six += arr[i];
    }
    cout << "Sum of first six: " << sum_six << endl;
    
    int k1 = 2, k2 = 5;
    int sum_range = 0;
    for (int i = k1; i <= k2 && i < size; i++) {
        sum_range += arr[i];
    }
    cout << "Sum from " << k1 << " to " << k2 << ": " << sum_range << endl;
    
    double average = 0;
    if (size > 0) {
        average = (double)sum / size;
    }
    cout << "Average of all: " << average << endl;
    
    int s1 = 1, s2 = 8;
    double average_range = 0;
    int count = 0;
    for (int i = s1; i <= s2 && i < size; i++) {
        average_range += arr[i];
        count++;
    }
    if (count > 0) {
        average_range = average_range / count;
    }
    cout << "Average from " << s1 << " to " << s2 << ": " << average_range << endl;
}