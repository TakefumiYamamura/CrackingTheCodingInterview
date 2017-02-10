#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long make_change(vector<long long> coins, long long money) {
	vector<vector<long long> > dp;
	dp.resize(coins.size());
	for (int i = 0; i < coins.size(); ++i)
	{
		dp[i].resize(money+1);
		for (int j = 0; j <= money; ++j)
		{
			dp[i][j] = 0;
		}
	}
	int itr = 0;
	while(money >= itr * coins[0]){
		dp[0][itr * coins[0] ]++;
		itr++;
	}
	for (int i = 1; i < coins.size(); ++i)
	{
		for (int j = 0; j <= money; ++j)
		{
			int coins_num = 0;
			while(j - coins[i] * coins_num >= 0){
				dp[i][j] += dp[i-1][j-coins[i] * coins_num];
				coins_num++;
			}
		}
	}
	return dp[coins.size()-1][money];
}

int main(){
    long long n;
    long long m;
    cin >> n >> m;
    vector<long long> coins;
    for(int coins_i = 0;coins_i < m;coins_i++){
    	long long tmp;
    	cin >> tmp;
    	coins.push_back(tmp);
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
