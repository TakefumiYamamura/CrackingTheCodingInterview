#include <iostream>
#include <algorithm>

using namespace std;

int longestSequence(int n_){
	int n = n_; 
	int maxAns = 0;
	int tmp = 0;
	int beforeSum = 0;
	int i = 0;
	while( (n >> i) > 0){
		if( (n >> i)& 1){
			tmp++;
			maxAns = max(tmp, maxAns);
		}else{
			maxAns = max(maxAns, tmp + beforeSum + 1);
			if((n >> (i - 1) & 1) && (n >> (i + 1) & 1)){
				beforeSum = tmp;
			}
			tmp = 0;
		}
		// cout << tmp << endl;
		i++;
	}
	return maxAns;
}

int main(){
	cout << longestSequence(1775) << endl;
}