class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	if(n == 0) return;
    	int m = matrix[0].size();
    	vector<int> check_row = vector<int>(n, 0);
    	vector<int> check_val = vector<int>(m, 0);
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if(matrix[i][j] == 0){
    				check_row[i] = 1;
    				check_val[j] = 1;
    			}
    		}
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		if(check_row[i]){
    			for (int j = 0; j < m; ++j)
    			{
    				matrix[i][j] = 0;
    			}
    		}
    	}
    	for (int i = 0; i < m; ++i)
    	{
    		if(check_val[i]){
    			for (int j = 0; j < n; ++j)
    			{
    				matrix[j][i] = 0;
    			}
    		}
    	}
    	return ;
    }
};