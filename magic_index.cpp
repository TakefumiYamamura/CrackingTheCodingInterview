#include <vector>
#include <iostream>

using namespace std;

int find_magic_index(vector<int> array){
	int low = 0;
	int up = array.size() - 1;
	while(low <= up){
		int mid = (low + up) / 2;
		if(array[mid] ==  mid){
			return mid;
		}else if(array[mid] < mid){
			up = mid-1;
		}else{
			low = mid+1;
		}
	}
	return -1;
}


int find_magic_index_with_duplicate(vector<int> array){
	int low = 0;
	int up = array.size() - 1;
	while(low <= up){
		int mid = (low + up) / 2;
		if(array[mid] ==  mid){
			return mid;
		}else if(array[mid] < mid){
			up = mid-1;
			for(int i = array[mid] + 1; i < array.size(); i++){
				if(array[i] == i){
					return i;
				}
			}
		}else{
			low = mid+1;
			for(int i = 0; i < array[mid] - 1; i++){
				if(array[i] == i){
					return i;
				}
			}
		}
	}
	return -1;
}


int main(){
	vector<int> tmp1{-2, -1, 2, 4, 5, 7};
	cout << find_magic_index(tmp1) << endl;
	vector<int> tmp2{-2, -1, 3, 4, 5, 7};
	cout << find_magic_index(tmp2) << endl;
	vector<int> tmp3{-2, -1, 3, 5, 5, 5, 3, 3};
	cout << find_magic_index_with_duplicate(tmp3) << endl;
}
