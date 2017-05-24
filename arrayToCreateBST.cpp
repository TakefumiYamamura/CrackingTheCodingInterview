#include <vector>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	int rank;
	TreeNode(int x) : val(x), left(NULL), right(NULL), rank(0) {}
};

class BinarySearchTree
{
private:
	TreeNode *root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	void recursive_insert(TreeNode* cur, int val){
		if(cur == NULL) return;
		if(cur->val < val){
			if(cur->left == NULL){
				cur->left = new TreeNode(val);
				cur->left->rank = cur->rank + 1;
				return;
			}
			recursive_insert(cur->left, val);
		}else{
			if(cur->right == NULL){
				cur->right = new TreeNode(val);
				cur->right->rank = cur->rank + 1;
				return;
			}
			recursive_insert(cur->right, val);
		}
	}
	void insert(int val){
		if(root == NULL){
			root = new TreeNode(val);
			root->rank = 0;
		}else{
			TreeNode *cur = root;
			recursive_insert(cur, val);
		}
	}

	void show(){
		queue<TreeNode*> q;
		q.push(root);
		int before_rank = 0;
		while(!q.empty()){
			TreeNode* cur = q.front();
			q.pop();
			if(cur == NULL) continue;
			if(cur->rank != before_rank){
				cout << endl;
				before_rank = cur->rank;
			}
			cout << cur->val << " ";
			q.push(cur->right);
			q.push(cur->left);
		}
		cout << endl;
	}

	TreeNode* fetch_root(){
		return root;
	}
};

struct Node
{
	vector<int> array;
	unordered_map<int, bool> visited;
	unordered_map<int, int> indeg;
};

class Solver
{
private:
	unordered_map<int, bool> visited;
	unordered_map<int, vector<int> > um;
	unordered_map<int, int> indeg;
	int node_num;
	BinarySearchTree bst;
public:
	Solver(BinarySearchTree _bst){
		bst = _bst;
		node_num = 0;
	}

	void fetch_topological_order(TreeNode* cur){
		if(cur == NULL) return;
		visited[cur->val] = false;
		node_num++;
		if(cur->left != NULL){
			um[cur->val].push_back(cur->left->val);
			indeg[cur->left->val]++;
			fetch_topological_order(cur->left);
		}
		if(cur->right != NULL){
			um[cur->val].push_back(cur->right->val);
			indeg[cur->right->val]++;
			fetch_topological_order(cur->right);
		}
	}

	void exec(){
		fetch_topological_order(bst.fetch_root());
		vector<vector<int> > all_order;
		queue<Node> q;
		vector<int> start_array;
		Node start = {start_array, visited, indeg};
		q.push(start);
		while(!q.empty()){
			Node cur_node = q.front();
			q.pop();
			if(cur_node.array.size() == node_num){
				all_order.push_back(cur_node.array);
				continue;
			}
			for (auto itr = cur_node.visited.begin(); itr != cur_node.visited.end(); ++itr)
			{
				if(itr->second == false && cur_node.indeg[itr->first] == 0){
					unordered_map<int, bool> new_visited = cur_node.visited;
					new_visited[itr->first] = true;
					vector<int> next_array = cur_node.array;
					next_array.push_back(itr->first);
					unordered_map<int, int> new_indeg = cur_node.indeg;
					for (int i = 0; i < um[itr->first].size(); ++i)
					{
						new_indeg[ um[itr->first][i] ]--;
					}
					Node next = {next_array, new_visited, new_indeg};
					q.push(next);
				}
			}
		}

		for (int i = 0; i < all_order.size(); ++i)
		{
			for (int j = 0; j < all_order[i].size(); ++j)
			{
				cout << all_order[i][j] << " ";
			}
			cout << endl;
		}
	}
	
};

	


int main(){
	// vector<int> tst1{5, 8, 1, 3, 7};
	// vector<int> tst1{2, 1, 3};
	vector<int> tst1{50, 20, 10, 25, 5, 15};
	BinarySearchTree bst1 = BinarySearchTree();
	for (int i = 0; i < tst1.size(); ++i)
	{
		bst1.insert(tst1[i]);
	}
	bst1.show();
	Solver s = Solver(bst1);
	s.exec();
}

