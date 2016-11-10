#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MergeSort {
public:
	vector<int> array;
	int n;
	MergeSort();
	void input();
	void exec();
	void divide(int left, int right);
	void merge(int left, int right, int mid);
};

MergeSort::MergeSort(){
	input();
}

void MergeSort::input(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		array.push_back(tmp);
	}
}

void MergeSort::exec(){
	divide(0, n-1);

	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void MergeSort::divide(int left, int right){
    int mid = (right + left) / 2;
	if(left+1 < right){
		divide(left, mid);
		divide(mid+1, right);
	}
	merge(left, right, mid);
}

void MergeSort::merge(int left, int right, int mid){
	vector<int> L;

	for (int i = left; i <= mid; ++i)
	{
		L.push_back(array[i]);
	}

	vector<int> R;
	for (int i = mid+1; i <= right; ++i)
	{
		R.push_back(array[i]);
	}

	int l_index = 0;
	int r_index = 0;

	for (int i = left; i <= right; ++i)
	{
		if(l_index >= L.size()){
			while(i <= right){
				array[i] = R[r_index];
			    r_index++;
			    i++;
			}
			break;
		}

		if(r_index >= R.size()){
			while(i <= right){
				array[i] = L[l_index];
			    l_index++;
			    i++;
			}
			break;

		}

		if(r_index > l_index >= L.size() || L[l_index] > R[r_index]){
			array[i] = R[r_index];
			r_index++;
		}else{
			array[i] = L[l_index];
			l_index++;
		}
	}


}

int main(){
	MergeSort ms = MergeSort();
	ms.exec();
}
