enum Type{
	START = 0,
	GOAL = 1,
};

struct Node {
	int cur_id;
	int depth;
	vector<bool> visited;
	Type type;
};

class Solution {
private:
	vector<vector<int> > adj;
	unordered_map<int, int> visited_from_start;
	unordered_map<int, int> visited_from_goal;
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		vector<string> words = wordList;
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
					if(count > 1) break;
					if(str1[k] != str2[k]) count++;
				}
				if(count == 1){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		if(goal_i == -1) return 0;

		queue<Node> q;

		vector<bool> start_visited = vector<bool>(size, false);
		Node start_node = {start_i, 1, start_visited, START};
		start_node.visited[start_i] = true;

		vector<bool> goal_visited = vector<bool>(size, false);
		Node goal_node = {goal_i, 1, goal_visited, GOAL};
		goal_node.visited[goal_i] = true;
		q.push(start_node);
		q.push(goal_node);

		while(!q.empty()){
			Node cur_node = q.front();
			q.pop();
			if(cur_node.type == START){
				if(visited_from_goal.find(cur_node.cur_id) != visited_from_goal.end()) return cur_node.depth + visited_from_goal[cur_node.cur_id] - 1;
			}else{
				if(visited_from_start.find(cur_node.cur_id) != visited_from_goal.end()) return cur_node.depth + visited_from_start[cur_node.cur_id] - 1;
			}

			for (int i = 0; i < adj[cur_node.cur_id].size(); ++i)
			{
				vector<bool> visited = cur_node.visited;
				int next_i = adj[cur_node.cur_id][i];
				if(cur_node.type == GOAL && visited_from_goal.find(next_i) != visited_from_goal.end()) continue;
				if(cur_node.type == START && visited_from_start.find(next_i) != visited_from_start.end()) continue;
				if(visited[next_i]) continue;
				visited[next_i] = true;
				Node next_node = {next_i, cur_node.depth + 1, visited, cur_node.type};
				q.push(next_node);
				if(cur_node.type == START){
					visited_from_start[next_i] = next_node.depth;
				}else{
					visited_from_goal[next_i] = next_node.depth;
				}
			}
		}
		return 0;
	}
};
