class Solution {
private:
	vector<vector<int> > dp;
public:
	int recursive(int left, int right){
	    cout << left << " " << right <<endl;
		if(dp[left][right] != -1){
			return dp[left][right];
		}
		int sum = 0;
		int l_sum = 0;
		int r_sum = 0;
		for (int i = 0; i < left; ++i)
		{
			l_sum += recursive(i, left - 1 - i);
		}
		for (int i = 0; i < right; ++i)
		{
			r_sum += recursive(i, right - 1 - i);
		}
		l_sum = l_sum == 0 ? 1 : l_sum;
		r_sum = r_sum == 0 ? 1 : r_sum;
		return dp[left][right] = l_sum  * r_sum;
	}

    int numTrees(int n) {
    	if(n == 0) return 0;
    	dp = vector<vector<int> >(n, vector<int>(n, -1));
    	dp[0][0] = 1;
    	int ans = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		ans += recursive(i, n - 1 - i);
    	}
    	return ans;
    }
};
