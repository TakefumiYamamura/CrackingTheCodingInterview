#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;


vector<int> random_set(vector<int> arr, int k){
	assert(arr.size() >= k);
	vector<int> st;
	for (int i = arr.size() - 1 ; i > arr.size() - 1 - k ; --i)
	{
		int tmp = rand() % (i + 1);
		swap(arr[i], arr[tmp]);
		st.push_back(arr[i]);
	}
	return st;
}

int main(){
	vector<int> n;
	for (int i = 0; i < 25; ++i)
	{
		n.push_back(i);
	}
	vector<int> arr = random_set(n, 15);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
