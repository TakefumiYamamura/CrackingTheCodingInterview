#include <vector>
#include <iostream>

using namespace std;


void sort_maountain(vector<int>& arr){
	for (int i = 1; i + 1 < arr.size(); i = i + 2)
	{
		if(arr[i-1] > arr[i]){
			swap(arr[i-1], arr[i]);
		}
		if(arr[i] < arr[i+1]){
			swap(arr[i], arr[i+1]);
		}
	}
}

int main(){
	vector<int> array{5,3,1,2,3,6,4,11,17};
	sort_maountain(array);
	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}