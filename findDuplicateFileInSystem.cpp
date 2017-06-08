class Solution {
private:
	unordered_map<string, vector<string> > um;
public:
	void fetch_files(string str) {
		string pos = "";
		int i = 0;
		while(str[i] != ' ') {
			pos += str[i];
			i++;
		}
		i++;
		pos += '/';
		while(i < str.length()) {
			string file = pos;
			string key = "";
			while(str[i] != ' ' && i < str.length()) {
				file += str[i];
				i++;
				if(str[i] == '('){
					i++;
					while(str[i] != ')'){
						key += str[i];
						i++;
					}
					i++;
				}
			}
			um[key].push_back(file);
			i++;
		}
	}

    vector<vector<string>> findDuplicate(vector<string>& paths) {
    	for (int i = 0; i < paths.size(); ++i)
    	{
    		fetch_files(paths[i]);
    	}
    	vector<vector<string>> ans;
    	for(auto itr : um){
    		if(itr.second.size() != 1) ans.push_back(itr.second);
    	}
    	return ans;
    }
};
