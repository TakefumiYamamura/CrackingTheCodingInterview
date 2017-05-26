#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

struct Num
{
	int val;
	Num();
	Num(int val_) : val(val_){}
	Num operator + (const Num& n) {
		return Num(val + n.val);
	}
	Num operator - (const Num& n) {
		return Num(val + ~n.val + 1);
	}
	Num operator * (const Num& n) {
		int a = val;
		int b = n.val;
		int ans = 0;
		if(a > b) swap(a, b);
		bool b_is_nega = false;
		if(b < 0){
			b_is_nega = true;
			b = ~b + 1;
		}
		while(b > 0){
			if(b & 1){
				ans += a;
			}
			b = b >> 1;
			a = a + a;
		}
		return b_is_nega ? Num(~ans + 1) : Num(ans);
	}

	Num operator / (const Num& n) {
		int a = val;
		int b = n.val;
		assert(b != 0);
		bool a_is_nega = false;
		bool b_is_nega = false;
		if(a < 0){
			a = ~a + 1;
			a_is_nega = true;
		}
		if(b < 0){
			b = ~b + 1;
			b_is_nega = true;
		}
		bool ans_is_pos = a_is_nega == b_is_nega ? true : false;

		int ans = 0;
		int tmp = b;
		while(tmp <= a){
			tmp += b;
			ans++;
		}
		return ans_is_pos ? ans : ~ans + 1;
	}

};

int main(){
	Num n1 = Num(150);
	Num n2 = Num(160);
	Num n3 = n1 - n2;
	Num n4 = n2 - n1;
	Num n5 = n1 * n2;
	Num n6 = n1 / n2;
	cout << n3.val << endl;
	cout << n4.val << endl;
	cout << n5.val << endl;
	cout << n6.val << endl;
}
