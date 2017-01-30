#include <iostream>
#include <string>

using namespace std;

void printBit(int n){
	string str = "";
	while(n != 0){
		if(n & 1){
			str = "1" + str;
		}else{
			str = "0" + str;
		}
		n = n >> 1; 
	}
	cout << str << endl;
}

int updateBits(int n, int m, int i, int j){
	//clear the bits j through i in n
	printBit(m);
	int mask = ~0;
	for (int itr = i; itr <= j; ++itr)
	{
		mask = mask ^ (1 << itr); 
	}
	n &= mask;
	//shift m so  that it lines up with bits j through i
	m = m << i;
	printBit(m);
	// merge m and n
	return n | m;
}

int main(){
	int ans = updateBits(1024, 19, 2, 6);
	printBit(ans);
}
