class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n+1, n+1);
        dp[0] = 0;
        for(int j = 1; j <= n; j++){
            for(int i = 1; i * i <= j; i++){
                dp[j] = min(dp[j], dp[j - i*i] + 1);
            }
        }
        return dp[n];
    }
};
