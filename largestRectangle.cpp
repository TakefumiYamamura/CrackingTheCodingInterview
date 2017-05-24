class Solution {
private:
	vector<vector<int> > dp;
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> st_idx;
	    stack<int> st_original_idx;
	    stack<int> st_val;
        int size = heights.size();
        if(size == 0) return 0;
        int ans = 0;
        for (int i = 0; i < size; ++i)
        {
            if(st_val.empty() || st_val.top() <= heights[i]){
                st_idx.push(i);
                st_val.push(heights[i]);
                st_original_idx.push(i);
            }else if(st_val.top() > heights[i] ){
                while(!st_val.empty() && st_val.top() > heights[i]){
                    int cur = st_val.top();
                    cout << st_idx.top()  << " : " << st_val.top()  << " : " << cur * (i - st_idx.top() ) << endl;
                    ans = max(ans, cur * (i - st_idx.top() ));
                    st_val.pop();
                    st_idx.pop();
                    st_original_idx.pop();
                }
                int next_idx = st_val.empty() ? 0 : st_original_idx.top() + 1;
                st_idx.push(next_idx);
                st_val.push(heights[i]);
                st_original_idx.push(i);
            }
        }

        while(!st_val.empty()){

            ans = max(ans, st_val.top() * (size - st_idx.top()));
            st_idx.pop();
            st_val.pop();
            st_original_idx.pop();
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
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
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
            }
        }
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                dp[i][j] = dp[i][j] == 1 ? dp[i-1][j] + 1 : 0;
            }
        }

        for (int i = 0; i < rows; ++i)
        {
        	ans = max(largestRectangleArea(dp[i]), ans);
        }
        return ans;
    }
};