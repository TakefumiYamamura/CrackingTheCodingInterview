class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
    	map<vector<int>, vector<string> >hash;
    	for (int i = 0; i < strings.size(); ++i)
    	{
    		vector<int> tmp;
    		for (int j = 0; j < strings[i].length(); ++j)
    		{
    			int start = strings[i][0] - 'a';
    			int cur = strings[i][j] - 'a';
    			int dif = cur - start;
    			if(dif < 0) dif = 26 + dif;
    			// cout << (cur -start ) % 26 << " " << cur - start << " ";
    			tmp.push_back(dif);
    		}
    		// cout << endl;
    		hash[tmp].push_back(strings[i]);
    	}
    	vector<vector<string> > ans;
    	for (auto itr = hash.begin(); itr != hash.end() ; ++itr)
    	{
    		ans.push_back(itr->second);
    	}
    	return ans;
        
    }
};