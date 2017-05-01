class Solution {
private:
	vector<vector<pair<int, int> > > map;

public:
    int maximalSquare(vector<vector<char> >& matrix) {
    	int rows = matrix.size();
    	if(rows == 0) return 0;
    	int cols = matrix[0].size();
    	int ans = 0;
    	map.resize(rows);
    	for (int i = 0; i < rows; ++i)
    	{
    		map[i].resize(cols);
    		for (int j = 0; j < cols; ++j)
    		{
    			map[i][j] = make_pair(0, 0);
    		}
    	}
    	for (int i = 0; i < rows; ++i)
    	{
    		int tmp = 0;
    		for (int j = cols - 1; j >= 0; --j)
    		{
    			if(matrix[i][j] == '1'){
    				tmp++;
    			}else{
    				tmp = 0;
    			}
    			map[i][j].first = tmp;
    		}
    	}

    	for (int i = 0; i < cols; ++i)
    	{
    		int tmp = 0;
    		for (int j = rows - 1; j >= 0; --j)
    		{
    			if(matrix[j][i] == '1'){
    				tmp++;
    			}else{
    				tmp = 0;
    			}
    			map[j][i].second = tmp;
    		}
    	}

    	for (int i = 0; i < rows; ++i)
    	{
    		for (int j = 0; j < cols; ++j)
    		{
                cout << map[i][j].first << ":" << map[i][j].second <<" ";
    			ans = max(ans, min(map[i][j].first, map[i][j].second) );
    		}
            cout << endl;
    	}
    	return ans * ans;
    }
};
