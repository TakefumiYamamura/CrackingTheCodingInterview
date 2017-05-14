#include <iostream>


using namespace std;

int countFactZero1(int n){
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = i;
		while(tmp > 0){
			if(tmp % 5 == 0){
				count++;
			}else{
				break;
			}
			tmp /= 5;
		}
	}
	return count;
}

int countFactZero2(int n){
	int count = 0;
	int tmp = 5;
	while(tmp <= n){
		count += n/tmp;
		tmp *= 5; 
	}
	return count;
}


int main(){
	cout << countFactZero1(100) << endl;
	cout << countFactZero2(100) << endl;
}