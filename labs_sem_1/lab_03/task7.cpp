#include <iostream>
#include <string>
using namespace std;

void task7() {
    string city1 = "Moscow";
    string city2 = "Saint-Petersburg";
    string city3 = "Sochi";
    
    cout << "City 1: " << city1 << " (length " << city1.length() << ")" << endl;
    cout << "City 2: " << city2 << " (length " << city2.length() << ")" << endl;
    cout << "City 3: " << city3 << " (length " << city3.length() << ")" << endl;
    
    string the_longest = city1;
    string the_shortest = city1;
    
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
    
    cout << "The longest: " << the_longest << endl;
    cout << "The shortest: " << the_shortest << endl;
}