#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class HiddenArray
{
private:
	int n;
	int test;
	vector<int> array;
public:
	HiddenArray(int test){
		n = 1000;
		for (int i = 0; i < 100; ++i)
		{
			array.push_back(rand() % n);
		}
		array.push_back(test);
		sort(array.begin(), array.end());
	}

	int elementAt(int i){
		return i < array.size() ? array[i] : -1;
	}

	int binary_search(int target){
		int left = 0;
		int right = 1;
		while(elementAt(right) != -1){
			right *= 2; 
		}

		while(left <= right){
			int mid = (left + right) / 2;
			if(elementAt(mid) == target) return mid;
			if(elementAt(mid) == -1 || elementAt(mid) > target){
				right = mid-1;
			}else{
				left = mid+1;
			}
		}
		for (int i = 0; i < array.size(); ++i)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		return -1;
	}
};

int main(){
	HiddenArray ha = HiddenArray(555);
	cout << ha.binary_search(555) << endl;
	cout << ha.binary_search(10000) << endl;

}
