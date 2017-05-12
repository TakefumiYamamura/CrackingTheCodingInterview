enum Type{
	START = 0,
	GOAL = 1,
};

struct Node {
	int cur_id;
	vector<int> strs;
	vector<bool> visited;
	Type type;
};

class Solution {
private:
	vector<vector<int> > adj;
	unordered_map<int, vector<Node> > visited_from_start;
	unordered_map<int, vector<Node> > visited_from_goal;
	vector<string> words;
public:

	vector<string> concatReverese(vector<int> strs1, vector<int> strs2){
		vector<string> ans;
		for (int i = 0; i < strs1.size(); ++i)
		{
			ans.push_back(words[strs1[i]]);
		}
		for (int i = strs2.size() - 2; i >= 0; --i)
		{
			ans.push_back(words[strs2[i]]);
		}
		return ans;
	}

	vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
		words = wordList;
		words.push_back(beginWord);
		int size = words.size();
		int start_i = size - 1;
		int goal_i = -1;
		adj.resize(words.size());
		for (int i = 0; i < words.size(); ++i) {
			if(words[i] == endWord){
				goal_i = i;
			}
			for (int j = i + 1; j < words.size(); ++j) {
				string str1 = words[i];
				string str2 = words[j];
				int count = 0;
				for (int k = 0; k < str1.length(); ++k) {
					if(str1[k] != str2[k]) count++;
				}
				if(count == 1){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		vector<vector<string> > ans;
		if(goal_i == -1) return ans;
		queue<Node> q;

		vector<int> start_strs;
		start_strs.push_back(start_i);
		vector<bool> start_visited = vector<bool>(size, false);
		Node start_node = {start_i, start_strs, start_visited, START};
		start_node.visited[start_i] = true;
		visited_from_start[start_i].push_back(start_node);

		vector<int> goal_strs;
		goal_strs.push_back(goal_i);
		Node goal_node = {goal_i, goal_strs, start_visited, GOAL};
		goal_node.visited[goal_i] = true;
		visited_from_goal[goal_i].push_back(goal_node);

		q.push(start_node);
		q.push(goal_node);


		set<int> meet_points;
		int min_depth = INT_MAX / 2;

		while(!q.empty()){
			Node cur_node = q.front();
			q.pop();
			if(cur_node.type == START && visited_from_goal.find(cur_node.cur_id) !=  visited_from_goal.end() ){
				if(min_depth + 1 < cur_node.strs.size()) continue;
				min_depth = cur_node.strs.size();
				meet_points.insert(cur_node.cur_id);
				continue;
			}else if(cur_node.type == GOAL && visited_from_start.find(cur_node.cur_id) !=  visited_from_start.end()){
				if(min_depth + 1 < cur_node.strs.size()) continue;
				min_depth = cur_node.strs.size();
				meet_points.insert(cur_node.cur_id);
				continue;
			}


			for (int i = 0; i < adj[cur_node.cur_id].size(); ++i)
			{
				vector<bool> visited = cur_node.visited;
				int next_i = adj[cur_node.cur_id][i];
				if(visited[next_i]) continue;
				if(cur_node.type == GOAL && visited_from_goal.find(next_i) != visited_from_goal.end() && visited_from_goal[next_i][0].strs.size() < cur_node.strs.size() + 1 ) continue;
				if(cur_node.type == START && visited_from_start.find(next_i) != visited_from_start.end() && visited_from_start[next_i][0].strs.size() < cur_node.strs.size() + 1 ) continue;
				visited[next_i] = true;
				vector<int> next_strs = cur_node.strs;
				next_strs.push_back(next_i);
				Node next_node = {next_i, next_strs, visited, cur_node.type};
				q.push(next_node);
				if(cur_node.type == START){
					visited_from_start[next_i].push_back(next_node);
				}else{
					visited_from_goal[next_i].push_back(next_node);
				}
			}
		}

		for(auto itr = meet_points.begin(); itr != meet_points.end(); itr++){
			vector<Node> nodes_from_start = visited_from_start[*itr];
			vector<Node> nodes_from_goal = visited_from_goal[*itr];
			for (int j = 0; j < nodes_from_start.size(); ++j)
			 {
			 	for (int k = 0; k < nodes_from_goal.size(); ++k)
			 	{
			 		if(nodes_from_start[j].strs.size() > min_depth + 1 || nodes_from_goal[k].strs.size() > min_depth + 1) continue;
			 		ans.push_back(concatReverese(nodes_from_start[j].strs, nodes_from_goal[k].strs));
 				}
			 } 
		}

		int min_len = INT_MAX / 2;

		for (int i = 0; i < ans.size(); ++i)
		{
			int len = ans[i].size();
			min_len = min(min_len, len);
		}

		vector<vector<string> > new_ans;

		for (int i = 0; i < ans.size(); ++i)
		{
			int len = ans[i].size();
			if(len == min_len) new_ans.push_back(ans[i]);
		}

		return new_ans;
	}
};
