#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define MOD 1000000007
// INT_MAX
using namespace std;

class InPrePost
{
public:
	string isPossible(vector <string> s, vector <int> a1, vector <int> a2, vector <int> a3) {
		unordered_map<string, unordered_map<int, vector<int> > > dp;
		int root = a1[0];
		dp["pre"][root] = a1;
		dp["in"][root]  = a2;
		dp["post"][root]= a3;

	}
};
