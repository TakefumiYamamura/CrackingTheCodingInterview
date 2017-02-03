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
	vector<TreeNode*> nodes;
public:
	void traverse(TreeNode* node){
		if(node == NULL) return;
		traverse(node->left);
		nodes.push_back(node);
		traverse(node->right);
	}

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	traverse(root);
    	for (int i = 0; i < nodes.size()-1; ++i)
    	{
    		if(nodes[i] == p){
    			return nodes[i+1];
    		}
    	}
    	return NULL;
    }
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	TreeNode* cur = p;
    	if(cur == NULL){
    		return NULL;
    	}else{
    		cur = cur->right;
    	}
    	while(cur != NULL && cur != ){
    		cur = cur->left
    	}

    	traverse(root);
    	for (int i = 0; i < nodes.size()-1; ++i)
    	{
    		if(nodes[i] == p){
    			return nodes[i+1];
    		}
    	}
    	return NULL;
    }
};