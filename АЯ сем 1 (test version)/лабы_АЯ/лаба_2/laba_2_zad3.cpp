#include <iostream>
using namespace std;
//Лаба 1 Задание 3
int main() {
	int n;
	 
	for (int i = 1; i < 10; i++){
	    cout<<i<<" * 7 = "<<(i * 7)<<endl;
	}
	
	cout<<"Введите n для умножения: "<<endl;
	cin>>n;
	for (int i = 1; i < 10; i++) {
	    cout<<i<<" * "<<n<<" = "<<(i * n)<<endl;
	}
	
}
