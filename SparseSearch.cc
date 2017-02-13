#include <string>
#include <iostream>
#include <vector>

using namespace std;

class SparseSearch
{
private:
	vector<string> array;
	string tar;

public:
	SparseSearch(){
		array.push_back("at");
		array.push_back("");
		array.push_back("");
		array.push_back("");
		array.push_back("ball");
		array.push_back("");
		array.push_back("");
		array.push_back("car");
		array.push_back("");
		array.push_back("");
		array.push_back("dad");
		array.push_back("");
		array.push_back("");
		tar = "ball";
	}
	int binarySearch(int left, int right){
		int mid = (left+right)/2;
		if(left == right){
			if(array[mid] == tar) return mid;
			return -1;
		}
		if(left > right) return -1;

		// midがから文字なら最も近い空でない文字列を探す。
		if(array[mid] == ""){
			int idx1 = mid-1;
			int idx2 = mid+1;
			while(left <= idx1 && idx2 <= right){
				if(array[idx1] != ""){
					mid = idx1;
					break;
				}
				if(array[idx2] != ""){
					mid = idx2;
					break;
				}
				idx1--;
				idx2++;
			}
		}

		if(array[mid] == tar) return mid;
		if(array[mid] > tar){
			return binarySearch(left, mid-1);
		}else{
			return binarySearch(mid+1, right);
		}
	}

	void exec(){
		cout << binarySearch(0, array.size()-1) << endl;
	}	
};

int main(){
	SparseSearch s = SparseSearch();
	s.exec();
}
