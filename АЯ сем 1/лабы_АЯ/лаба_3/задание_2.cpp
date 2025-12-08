#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int size = 10;
    int arr[size];
    
    cout << "Enter " << size << " array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
 
    cout << "Your array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // 1. Сумма всех элементов
    int sumAll = 0;
    for (int num:arr) {
        sumAll += num;
    }
    cout << "1. Sum of all elements: " << sumAll << endl;
    
    // 2. Сумма квадратов
    int sumSquares = 0;
    for (int i = 0; i < size; i++) {
        sumSquares += arr[i] * arr[i];
    }
    cout << "2. Sum of squares: " << sumSquares << endl;
    
    // 3. Сумма первых шести элементов
    int sumFirstSix = 0;
    for (int i = 0; i < 6; i++) {
        sumFirstSix += arr[i];
    }
    cout << "3. Sum of first six elements: " << sumFirstSix << endl;
    
    // 4. Сумма элементов с k1 по k2
    int k1, k2;
    cout << "Enter k1 and k2 (element numbers): ";
    cin >> k1 >> k2;
    k1--; k2--; 
    
    int sumK = 0;
    for (int i = k1; i <= k2; i++) {
        if (i >= 0 && i < size) {
            sumK += arr[i];
        }
    }
    cout << "4. Sum from " << k1+1 << " to " << k2+1 << ": " << sumK << endl;
    
    // 5. Среднее арифметическое всех элементов
    double avgAll = (double)sumAll / size;
    cout << "5. Average of all elements: " << avgAll << endl;
    
    // 6. Среднее арифметическое элементов с s1 по s2
    int s1, s2;
    cout << "Enter s1 and s2 (element numbers): ";
    cin >> s1 >> s2;
    s1--; s2--; 
    
    int sumS = 0;
    int count = 0;
    for (int i = s1; i <= s2; i++) {
        if (i >= 0 && i < size) {
            sumS += arr[i];
            count++;
        }
    }
    
    double avgS = 0;
    if (count > 0) {
        avgS = (double)sumS / count;
    }
    cout << "6. Average from " << s1+1 << " to " << s2+1 << ": " << avgS << endl;
    
    return 0;
}