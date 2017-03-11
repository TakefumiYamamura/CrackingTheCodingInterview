#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class MinMaxMax
{
public:
	long long findMing(vector <int> a, vector <int> b, vector <int> w, vector <int> v){
		int ans = 0;
		while(c > b){
			b += (b - a);
			ans++;
		}
		return ans;
	}
};
