struct Node
{
	int depth;
	vector<string> map;
	Node(int _depth, vector<string> _map) : depth(_depth), map(_map) {}
};

class Solution {
private:
	int size;
public:
	bool cross_check(int x, int y, vector<string> map){
		for (int i = 0; max(x + i, y + i) < size; ++i)
		{
			if(map[x + i][y + i] == 'Q') return false;
		}

		for (int i = 0; min(x - i, y - i) >= 0; ++i)
		{
			if(map[x - i][y - i] == 'Q') return false;
		}

		for (int i = 0; x + i < size && y - i >= 0; ++i)
		{
			if(map[x + i][y - i] == 'Q') return false;
		}

		for (int i = 0; y + i < size && x - i >= 0; ++i)
		{
			if(map[x - i][y + i] == 'Q') return false;
		}
		return true;
	}

	bool horizontal_check(int y, vector<string> map){

		for (int i = 0; i < size; ++i)
		{
			if(map[i][y] == 'Q') return false; 
		}
		return true;
	}


	bool check(int x, int y, vector<string> map){
		return cross_check(x, y, map) && horizontal_check(y, map);
	}

    vector<vector<string>> solveNQueens(int n) {
    	size = n;
    	queue<Node> q;
    	vector<string> start_map;
    	for (int i = 0; i < size; ++i)
    	{
    		string tmp = "";
    		for (int j = 0; j < size; ++j)
    		{
    			tmp += ".";
    		}
    		start_map.push_back(tmp);
    	}
    	Node start = Node(0, start_map);
    	q.push(start);
    	vector<vector<string> > ans;
    	while(!q.empty()){
    		Node cur = q.front();
    		q.pop();
    		if(cur.depth == size){
    			ans.push_back(cur.map);
    			continue;
    		}
    		for (int i = 0; i < size; ++i)
    		{
    			if(check(cur.depth, i, cur.map)){
    				vector<string> new_map = cur.map;
    				new_map[cur.depth][i] = 'Q';
    				Node new_node = Node(cur.depth+1, new_map);
    				q.push(new_node);
    			}
     		}
    	}
    	return ans;
    }
    int totalNQueens(int n) {
        return solveNQueens(n).size(); 
        
    }
};
