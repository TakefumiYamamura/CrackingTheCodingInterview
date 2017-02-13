#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class BearFair
{
public:
	string isFair(int n, int b, vector<int> upTo, vector<int> quantity){
		vector<pair<int, int> > pairs(upTo.size()); 
		for (int i = 0; i < upTo.size(); ++i)
		{
			pairs[i] = make_pair(upTo[i], quantity[i]);
		}
		sort(pairs.begin(), pairs.end());
		for (int i = 1; i < upTo.size(); ++i)
		{
			if
		}

	}
};