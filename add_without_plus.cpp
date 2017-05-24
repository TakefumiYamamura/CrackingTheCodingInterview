#include <iostream>

using namespace std;


int add(int a, int b){
	int tmp1 = a ^ b;
	int tmp2 = a & b;
	if(tmp2 == 0){
		return tmp1;
	}else{
		return add(tmp1, tmp2 << 1);
	}
}

int main(){
	cout << add(243, 5415) << endl;
}
