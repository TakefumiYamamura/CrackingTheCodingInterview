class Solution {
public:
	const int mod = 1e9 + 7;
    int checkRecord(int n) {
    	vector<vector<int > > dp;
    	// dp.resize(n+1);
    	// for (int i = 0; i < n+1; ++i)
    	// {
    		dp.resize(2);
    		for (int j = 0; j < 2; ++j)
    		{
    			dp[j].resize(3);
    			for (int k = 0; k < 3 ; ++k)
    			{
    				dp[j][k] = 0;
    			}
    		}
    	// }
    	dp[1][0] = 1;
    	dp[0][1] = 1;
    	dp[0][0] = 1;
    	for (int i = 2; i < n+1; ++i)
    	{
            vector<vector<int > > new_dp = vector<vector<int> >(2, vector<int>(3, 0));
    		for (int j = 0; j < 2; ++j)
    		{
    			if(dp[j][0] != 0) new_dp[j][1] = (((new_dp[j][1] + dp[j][0]) % mod)) % mod;
    			if(dp[j][1] != 0) new_dp[j][2] = (((new_dp[j][2] + dp[j][1]) % mod)) % mod;
    		}
    		for (int k = 0; k < 3 ; ++k)
    		{
    			if(dp[0][k] != 0) new_dp[1][0] = (((new_dp[1][0] + dp[0][k]) % mod)) % mod;
    			if(dp[1][k] != 0) new_dp[1][0] = (((new_dp[1][0] + dp[1][k]) % mod)) % mod;
    			if(dp[0][k] != 0) new_dp[0][0] = (((new_dp[0][0] + dp[0][k]) % mod)) % mod;
    		}
            dp = new_dp;
    	}
    	int ans = 0;
	    for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 3 ; ++k)
			{
				ans = (ans + dp[j][k]) % mod;
			}
		}
    	return ans;

        
    }
};