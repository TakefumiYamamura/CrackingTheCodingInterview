/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	vector<vector<int > > paths;
public:
	void findPaths(TreeNode* node, int sum, vector<int> path){
		if(node == NULL) return;
		path.push_back(node->val);
		if(sum == node->val && node->left == NULL && node->right == NULL) paths.push_back(path);
		findPaths(node->left, sum - node->val, path);
		findPaths(node->right, sum - node->val, path);	
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> path;
    	findPaths(root, sum, path);
    	return paths;        
    }
};