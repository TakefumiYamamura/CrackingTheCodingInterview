struct Node
{
	int cur;
	int depth;
	vector<string> tmp_ans;
	vector<vector<int> > tmp_g;
	// Node(int cur_, int depth_, vector<string> tmp_ans_, vector<vector<int> > tmp_g_) : cur(cur_), depth(depth_), tmp_ans(tmp_ans_), tmp_g_
	// ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	map<string, int> hash;
	vector<string> word_list;
	vector<vector<int> > g;
	int n;
	vector<string> ans;
	int ticket_num;
	bool dfs(int cur, int depth, vector<string> tmp_ans, vector<vector<int> > tmp_g){
		if(depth == ticket_num){
			ans = tmp_ans;
			return true;
		}

		for (int i = 0; i < n; ++i)
		{
		 	if(tmp_g[cur][i] >= 1){
		 		vector<string> next_ans = tmp_ans;
		 		next_ans.push_back(word_list[i]);
		 		vector<vector<int> > next_g = tmp_g;
		 		next_g[cur][i]--;
		 		if(dfs(i, depth+1, next_ans, next_g)) return true;
		 	}
		} 
		return false;
	}

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
    	ticket_num = tickets.size();
    	
    	for (int i = 0; i < tickets.size(); ++i)
    	{
    		if(hash.find(tickets[i].first) == hash.end()){
    			hash[tickets[i].first] = 1;
    		}
    		if(hash.find(tickets[i].second) == hash.end()){
    			hash[tickets[i].second] = 1;
    		}
    	}

    	int idx = 0;
    	for (auto itr = hash.begin(); itr != hash.end() ; ++itr)
    	{
    		itr->second = idx;
    		word_list.push_back(itr->first);
    		idx++;
    	}

    	n = hash.size();
    	g = vector<vector<int> >(n, vector<int>(n, 0) );

    	for (int i = 0; i < tickets.size(); ++i)
    	{
    		int i1 = hash[tickets[i].first];
    		int i2 = hash[tickets[i].second];
    		g[i1][i2]++;
    	}

    	vector<string> tmp_ans;
    	tmp_ans.push_back("JFK");

    	Node start = Node{hash["JFK"], 0 , tmp_ans, g};
    	stack<Node> s;
    	s.push(start);
    	while(!s.empty()){
    		Node cur_node = s.top();
    		s.pop();

    		if(cur_node.depth == ticket_num){
				ans = cur_node.tmp_ans;
				break;
			}
			// for (int i = 0; i < cur_node.tmp_ans.size(); ++i)
			// {
			// 	cout << cur_node.tmp_ans[i] << " ";
			// }
			// cout << endl;

			for (int i = n-1; i >= 0; --i)
			{
			 	if(cur_node.tmp_g[cur_node.cur][i] >= 1){
			 		vector<string> next_ans = cur_node.tmp_ans;
			 		next_ans.push_back(word_list[i]);
			 		vector<vector<int> > next_g = cur_node.tmp_g;
			 		next_g[cur_node.cur][i]--;
			 		Node next_node = Node{i, cur_node.depth+1, next_ans, next_g};
			 		s.push(next_node);
			 	}
			}
			// cout << "test" << endl;
    	}
    	return ans;
    }
};