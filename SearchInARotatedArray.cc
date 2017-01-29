#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SearchInARotatedArray
{
private:
	int n;
	vector<int> a;
	int k;
public:
	SearchInARotatedArray(){
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cin >> k;
	}
	// void binary_search(int l, int r){
	// 	while(l <= r){
	// 		int mid = (l + r) / 2;
	// 		if(a[mid] == k){
	// 			cout << mid << endl;
	// 		}else if(a[mid] < k){
	// 			r = mid;
	// 		}else{
	// 			l = mid;
	// 		}
	// 		if(l == r) break;
	// 	}
	// 	cout << -1 << endl;
	// }

	void exec(){
		int l = 0;
		int r = n-1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(a[mid] == k){
				cout << mid << endl;
				return;
			}
			if(l == r) break;
			if(a[mid] > a[l]){
				if(a[l] <= k && k <= a[mid]){
					// binary_search(l, mid);
					cout << lower_bound(a.begin()+l, a.begin()+mid, k) - a.begin() << endl;
					return;
				}else{
					l = mid;
				}
			}else{
				if(a[mid] <= k && k <= a[r]){
					// binary_search(l, mid);
					cout << lower_bound(a.begin()+mid, a.begin()+r, k) - a.begin() << endl;
					return;
				}else{
					r = mid;
				}
			}
		}
		// not found
		cout << -1 << endl;
	}
};


int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		SearchInARotatedArray solution = SearchInARotatedArray();
		solution.exec();
	}

}
