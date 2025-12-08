#include <iostream>
#include <string>
using namespace std;
using str = string;
int main() {
    str city1, city2, city3;
    str the_longest, the_shortest;
    
    cout << "Enter first city: ";
    cin >> city1;
    cout << "Enter second city: ";
    cin >> city2;
    cout << "Enter third city: ";
    cin >> city3;
    
    the_longest = city1;
    the_shortest = city1;
    
    if (city2.length() > the_longest.length()) {
        the_longest = city2;
    }
    if (city3.length() > the_longest.length()) {
        the_longest = city3;
    }
    
    if (city2.length() < the_shortest.length()) {
        the_shortest = city2;
    }
    if (city3.length() < the_shortest.length()) {
        the_shortest = city3;
    }
    
    cout << "The longest city: " << the_longest << endl;
    cout << "The shortest city: " << the_shortest << endl;
    
    return 0;
}