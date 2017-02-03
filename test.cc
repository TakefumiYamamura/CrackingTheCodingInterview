#include <string>
#include <iostream>
using namespace std;

void makeHand(string str, int d, int n){
	if(d == n){
		cout << str << endl;
		return;
	}
	makeHand(str + "グー", d+1, n);
	makeHand(str + "チョキ", d+1, n);
	makeHand(str + "パー", d+1, n);
}

int main(){
	int n;
	cin >> n;
	makeHand("", 0, n);
	cout << INT_MIN << endl;
}
