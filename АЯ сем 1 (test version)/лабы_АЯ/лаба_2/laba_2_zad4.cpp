#include <iostream>
using namespace std;
//Лаба 2 Задание 4
int main() {
    int a, b;
    //for (int i = 8; i < 16; i++) {
    //    for (int j = 8; j < 16; j++) {
    //        cout<<i<<" * "<<j<<" = "<<(i * j)<<endl;
    //    }
    //}
	
	//cout<<"Введите а для умножения от а до 20: "<<endl;
	//cin>>a;
	//for (int i = a; i <= 20; i++) {
	//    for (int j = a; j <= 20; j++) {
	//        cout<<i<<" * "<<j<<" = "<<(i * j)<<endl;
	//    }
	//}
	
	//cout<<"Введите b для умножения от 1 до b: "<<endl;
	//cin>>b;
	//for (int i = 1; i <= b; i++) {
	//    for (int j = 1; j <= b; j++) {
	//        cout<<i<<" * "<<j<<" = "<<(i * j)<<endl;
    //    }
	//}
	
	cout<<"Введите а и b для умножения от а до b: "<<endl;
	cin>>a>>b;
	for (int i = a; i <= b; i++) {
	    for (int j = a; j <= b; j++) {
	        cout<<i<<" * "<<j<<" = "<<(i * j)<<endl;
	    }
	}
	
}
