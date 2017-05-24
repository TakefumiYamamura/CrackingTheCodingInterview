#include <iostream>
#include <vector>

using namespace std;

int nth_magic_number(int n) {
	vector<int> dp;
    dp.resize(n);
    dp[0] = 1;
    int id7 = 0;
    int id3 = 0;
    int id5 = 0;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = min(min(dp[id7] * 7, dp[id3] * 3), dp[id5] * 5);
        if(dp[i] == dp[id7] * 7) id7++;
        if(dp[i] == dp[id3] * 3) id3++;
        if(dp[i] == dp[id5] * 5) id5++;
    }
    return dp[n-1];
}

int main(){
	cout << nth_magic_number(13) << endl;
}
