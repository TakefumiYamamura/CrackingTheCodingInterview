#include <iostream>
#include <climits>
using namespace std;
// 正の数なら1を返す
// 負の数のビットは引きずられる
// http://qiita.com/shr_em/items/3f07508372baf09681cd
int postive_check(int x){
	return 1^( (x >> 31) & 1) ;
}

int get_max(int a, int b){
	// 符号が同じなら1異なる場合0
	int check_overflow = 1 ^ postive_check(a) ^ postive_check(b);	
	int k = postive_check(a - b);
	return check_overflow * (a * k + b * (k^1)) + (1 ^ check_overflow) * (a * postive_check(a) + b * postive_check(b));
}


int main(){
	cout << get_max(100,5000) << endl;
	cout << get_max(100, -5000) << endl;
	cout << get_max(INT_MAX, INT_MIN) << endl;
}
