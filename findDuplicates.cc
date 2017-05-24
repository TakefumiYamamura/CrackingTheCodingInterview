#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>

using namespace std;

int main(){
	bitset<32000> bs;
	vector<int> array;
	for (int i = 0; i < 32000; ++i)
	{
		array.push_back(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		array.push_back(rand() % 32000);
	}

	for (int i = 0; i < array.size(); ++i)
	{
		if(bs[array[i]]) cout << array[i] << endl;
		bs[array[i]] = true; 
	}
}
