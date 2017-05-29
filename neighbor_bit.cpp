#include <iostream>
#include <string>

using namespace std;

void print_bit(int n) {
	string ans = "";
	while(n > 0) {
		if(n & 1) {
			ans = "1" + ans;
		} else {
			ans = "0" + ans;

		}
		n >>= 1;
	}
	cout << ans << endl;
}


void fetch_neighbor(int n){
	if(n == 0){
		cout << "There is no answer." << endl;
		return;
	}
	int i;
	int tmp = n;
	int first_one = 0;
	int finish_one = 0;
	int cnt = 0;
	while(tmp > 0){
		if(tmp & 1){
			first_one = cnt;
			while(tmp & 1){
				tmp >>= 1;
				cnt++;
			}
			finish_one = cnt;
			break;
		}
		tmp >>= 1;
		cnt++;
	}
	// cout << finish_one <<  " " << first_one << endl;
	int next_neighbor = n ^ (1 << finish_one) ^ (1 << (finish_one - 1));
	cout << next_neighbor << endl;
	cout << "next     : ";
	print_bit(next_neighbor);
	int before_neighbor = n ^ (1 << first_one) ^ (1 << (first_one - 1));
	cout << before_neighbor << endl;
	cout << "before   : ";
	print_bit(before_neighbor); 
}

int main(){
	cout << "original : ";
	print_bit(13948);
	fetch_neighbor(13948);
	// print_bit(8);
	// fetch_neighbor(8);
}
