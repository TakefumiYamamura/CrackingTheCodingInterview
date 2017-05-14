class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    	unordered_map<int, vector<int> > um;
    	bool flag = true;
    	for (int i = 0; i < ppid.size(); ++i)
    	{
    		if(ppid[i] == kill || pid[i] == kill) flag = false;
    		um[ppid[i]].push_back(pid[i]);
    	}

    	vector<int> ans;
    	if(flag) return ans;
    	queue<int> q;
    	q.push(kill); 
    	while(!q.empty()){
    		int cur = q.front();
    		ans.push_back(cur);
    		q.pop();
    		for (int i = 0; i < um[cur].size(); ++i)
    		{
    			q.push(um[cur][i]);
    		}
    	}
    	return ans;
    }
};
