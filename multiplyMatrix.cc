class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rows = A.size();
        int cols = B[0].size();
        int len = A[0].size();
        vector<vector<int> > ans;
        ans = vector<vector<int> >(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int tmp_ans = 0;
                for (int k = 0; k < len; ++k)
                {
                    tmp_ans += A[i][k] * B[k][j];
                }
                ans[i][j] = tmp_ans;
            }
        }
        return ans;
    }
};