#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> a, vector<int> b, int aSize, int bSize){
	int itrA = aSize - 1;
	int itrB = bSize - 1;
	for (int i = aSize + bSize - 1; i >= 0 ; --i)
	{
		int tmp;
		if(itrA < 0){
			a[i] = b[itrB];
			itrB--;
			continue;
		}
		//can remove this section
		if(itrB < 0){
			a[i] = a[itrA];
			itrA--;
			continue;
		}
		if(a[itrA] > b[itrB]){
			tmp = a[itrA];
			itrA--;
		}else{
			tmp = b[itrB];
			itrB--;
		}
		a[i] = tmp;
	}
	for (int i = 0; i < aSize + bSize; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < 10; ++i)
	{
		b.push_back(13 + i);
	}
	a.resize(30);
	for (int i = 0; i < 10; ++i)
	{
		a[i] = i + 3;
	}
	merge(a, b, 10, 10);
}