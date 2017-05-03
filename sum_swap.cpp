#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void sum_swap(vector<int> a, vector<int> b){
	int sum_a = 0;
	int sum_b = 0;
	unordered_map<int, bool> um_a;
	unordered_map<int, bool> um_b;
	for (int i = 0; i < a.size(); ++i)
	{
		sum_a += a[i];
		um_a[a[i]] = true;
	}

	for (int i = 0; i < b.size(); ++i)
	{
		sum_b += b[i];
		um_b[b[i]] = true;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		int two_b = sum_b - sum_a + 2 * a[i];
		if(two_b % 2 == 0 && um_b[two_b/2]){
			cout << a[i] << " : " << two_b/2 << endl;
		}
	}



}

int main(){
	vector<int> a{4, 1, 2, 1, 1, 2};
	vector<int> b{3, 6, 3, 3};
	sum_swap(a, b);
}
