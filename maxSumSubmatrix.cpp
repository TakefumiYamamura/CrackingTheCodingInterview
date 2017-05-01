class Solution {
private:
	vector<vector<int> > dp;
	int rows;
	int cols;
	vector<vector<int> > new_matrix;

public:
	void set_dp(){
	    dp = new_matrix;

		for (int i = 1; i < rows; ++i)
		{
			dp[i][0] += dp[i-1][0];
		}
		for (int i = 1; i < cols; ++i)
		{
			dp[0][i] += dp[0][i-1];
		}

		for (int i = 1; i < rows; ++i)
		{
			for (int j = 1; j < cols; ++j)
			{
				dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	}

	int fetch_sum(int x1, int y1, int x2, int y2)
	{
		int tmp1 = (x1 == 0 || y1 == 0) ? 0 : dp[x1-1][y1-1];
		int tmp2 = x1 == 0 ? 0 : dp[x1-1][y2];
		int tmp3 = y1 == 0 ? 0 : dp[x2][y1-1];

		return dp[x2][y2] + tmp1 - tmp2 - tmp3;
	}

	int maxSumSubarray(const vector<int>& array, int k){
		set<int> st;
		st.insert(0);
		int ans = INT_MAX / 2 * -1;
		for (int i = 0; i < array.size(); ++i)
		{
			if(st.lower_bound(array[i] - k) == st.end()){
				st.insert(array[i]);
				continue;
			}
			ans = max(ans, array[i] - *st.lower_bound(array[i] - k) );
			st.insert(array[i]);
		}
		return ans;

	}

	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

		rows = matrix.size();
		if(rows == 0) return 0;
		cols = matrix[0].size();
		if(rows > cols){
			swap(cols, rows);
			new_matrix.resize(rows);
			for (int i = 0; i < rows; ++i)
			{
				new_matrix[i].resize(cols);
				for (int j = 0; j < cols; ++j)
				{
					new_matrix[i][j] = matrix[j][i];
				}
			}
		}else{
			new_matrix = matrix;
		}

		set_dp();

		int ans = INT_MAX / 2 * -1;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = i; j < rows; ++j)
			{
				vector<int> tmp_array;
				for (int k = 0; k < cols; ++k)
				{
					tmp_array.push_back(fetch_sum(i, 0, j, k));
				}
				ans = max(ans, maxSumSubarray(tmp_array, k) );
			}
		}
		return ans;
    }
};
