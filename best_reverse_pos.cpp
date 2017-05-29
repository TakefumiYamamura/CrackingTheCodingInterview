#include <iostream>
#include <algorithm>

using namespace std;

int best_reverse_len(int n){
	if(n == 0) return 1;
	int cur = 0;
	int before = 0; 
	int ans = 0;
	while(n > 0){
		if(n & 1){
			cur++;
			ans = max(ans, cur + before);
		} else {
			int next_n = n;
			next_n >>= 1;
			ans = max(ans, cur + 1);
			before = next_n & 1 ? cur + 1 : 0;
			cur = 0;
		}
		n >>= 1;
	}
	return ans;
}

int main() {
	cout << best_reverse_len(1775) << endl;
	cout << best_reverse_len(4) << endl;
	cout << best_reverse_len(0) << endl;
	cout << best_reverse_len(1) << endl;
}
