class Solution {
private:
    vector<vector<int> > dp;

public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();
        int ans = 0;
        dp.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            dp[i].resize(cols);
            for (int j = 0; j < cols; ++j)
            {
                dp[i][j] = ( (i == 0 || j == 0 ) && matrix[i][j] == '1' ) ? 1 : 0;
                ans = max(dp[i][j], ans);
            }
        }

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if(matrix[i][j] == '1'){
                    int left = dp[i-1][j];
                    int up = dp[i][j-1];
                    int up_left = dp[i-1][j-1];
                    dp[i][j] = min(min(left, up), up_left) + 1;
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans * ans;
    }
};
