class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg = vector<int>(numCourses, 0);

        vector<int> visited = vector<int>(numCourses, 0);
        vector<vector<int> > adj;
        adj.resize(numCourses); 
        for(int i = 0; i < prerequisites.size(); i++){
        	indeg[prerequisites[i].first]++;
        	adj[prerequisites[i].second].push_back(prerequisites[i].first); 
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i)
        {
        	if(indeg[i] == 0){
        		q.push(i);
        		ans.push_back(i);
        	}
        }

        while(!q.empty()){
        	int cur = q.front();
        	q.pop();
        	if(visited[cur] == 1) continue;

        	visited[cur] = 1;
        	for (int i = 0; i < adj[cur].size(); ++i)
        	{
        		if(visited[adj[cur][i]] == 0){
        		    indeg[adj[cur][i]]--;
        		    if(indeg[adj[cur][i]] == 0){
                        ans.push_back(adj[cur][i]);
                        q.push(adj[cur][i]);
        		    }
        		}
        	}
        }
        vector<int> emptyArray;
        return ans.size() == numCourses ? ans : emptyArray;
    }
};
