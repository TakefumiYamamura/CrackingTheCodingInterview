// struct Node{
// 	int idx;
// 	int indeg;
// 	bool operator < (const Node& right){	
// 		return indeg < right.indeg;
// 	}
// 	bool asc( const Node& left, const Node& right ) {
//     return left.indeg < right.indeg;
// 	}
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg = vector<int>(numCourses, 0);

        vector<int> visited = vector<int>(numCourses, 0);
        vector<vector<int> > adj;
        adj.resize(numCourses); 
        for(int i = 0; i < prerequisites.size(); i++){
        	indeg[prerequisites[i].second]++;
        	adj[prerequisites[i].first].push_back(prerequisites[i].second); 
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
        for (int i = 0; i < numCourses; ++i)
        {
        	if(visited[i] == 0) return false;
        }
        return true;
    }
};
