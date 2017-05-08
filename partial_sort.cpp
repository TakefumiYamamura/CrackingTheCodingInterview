#include <iostream>
#include <vector>
#include <map>

using namespace std;

void partial_sort(vector<int> arr){
	map<int, int> mp;
	int max_v = 0;
	int left = -1;
	int right = -1;
	for (int i = 0; i < arr.size(); ++i)
	{
		if(max_v <= arr[i]){
			max_v = arr[i];
			if(mp.find(arr[i]) == mp.end()) mp[arr[i]] = i;
		}else{
			auto itr = mp.upper_bound(arr[i]);
			if(left == -1) left = itr->second;
			left = min(left, itr->second);
			right = i;
		}
	}
	if(left == -1 && right == -1){
		cout << "sorted" << endl;
	}else{
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << left << " " << right << endl;
	}


}

int main(){
	vector<int> arr1{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	partial_sort(arr1);
	vector<int> arr2{1, 2, 4, 7, 10, 11, 12, 16, 18, 19};
	partial_sort(arr2);
	vector<int> arr3{1, 1, 1, 1, 1, 2, 3, 4, 1, 1};
	partial_sort(arr3);
	vector<int> arr4{1, 1, 1, 1, 1, 2, 2, 2, 1, 1};
	partial_sort(arr4);
	vector<int> arr5{1, 1, 1, 1, 1, 3, 1, 2, 1, 1};
	partial_sort(arr5);
}