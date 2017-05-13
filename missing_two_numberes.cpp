#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_map>
#include <map>
using namespace std;

void missing_two_nums(vector<int> arr, int n){
	int sum = 0;
	int products = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += i;
		products += i * i;
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		sum -= arr[i];
		products -= arr[i] * arr[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		if((sum - i) * (sum - i) == products - i * i) cout << i << endl;
	}

}

int main(){
	vector<int> arr;
	for (int i = 1; i <= 100; ++i)
	{
		if(i == 29 || i == 47) continue;
		arr.push_back(i);
	}
	missing_two_nums(arr, 100);
}
