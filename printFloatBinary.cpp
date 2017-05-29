#include <iostream>
#include <string>

using namespace std;

void printDoubleFromBinary(string binary){
	double ans = 0;
	double tmp = 1.0;
	for (int i = 0; i < binary.length(); ++i)
	{
		tmp /= 2.0;
		if(binary[i] == '1'){
			ans += tmp;
		}
	}
	cout << ans << endl;
}

void printFloatBinary(double num){
	if(num > 1 || num < 0){
		cout << "out of range" << endl;
		return;
	}
	string ans_binary = "";
	double tmp = 1.0;
	while(num > 0 && ans_binary.length() <= 32){
		tmp /= 2.0;
		if(num  >= tmp ){
			ans_binary += "1";
			num -= tmp;
		}else{
			ans_binary += "0";
		}
	}
	cout << ans_binary << endl;
	printDoubleFromBinary(ans_binary);
}

int main(){
	printFloatBinary(0.1324325);
	printFloatBinary(0.1325);
	printFloatBinary(0.25);
}
