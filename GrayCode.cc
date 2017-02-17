class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> ans;
    	if(n == 0){
    		ans.push_back(0);
    		return ans;
    	}
    	for (int i = 0; i < 2<<(n-1); ++i)
    	{
    		ans.push_back(i^(i >> 1));	
    	}
    	return ans;
    }
};