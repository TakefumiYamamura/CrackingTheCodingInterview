#include <iostream>

using namespace std;

void swap_two_nums(int &a, int &b){
	a = a - b; // a - b
	b = a + b; // a - b + b = a
	a = b - a;
}

int main(){
	int a = 100;
	int b = 10;
	cout << a << " " << b << endl;
	swap_two_nums(a, b);
	cout << a << " " << b << endl;
}
