class Solution {
private:
    vector<int> dp;
public:
    int nthUglyNumber(int n) {
        dp.resize(n);
        dp[0] = 1;
        int id2 = 0;
        int id3 = 0;
        int id5 = 0;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = min(min(dp[id2] * 2, dp[id3] * 3), dp[id5] * 5);
            if(dp[i] == dp[id2] * 2) id2++;
            if(dp[i] == dp[id3] * 3) id3++;
            if(dp[i] == dp[id5] * 5) id5++;
        }

        return dp[n-1];
    }
};
