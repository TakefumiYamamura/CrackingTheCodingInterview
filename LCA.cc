/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <map>
#include <queue>

struct dpTree{
	TreeNode* parent;
	TreeNode* child;
	bool operator < (const dpTree& x) const {
		if(parent->val == x.parent->val){
			return child->val < x.child->val;
		}
		return parent->val < x.parent->val;
  	}
};

class Solution {
private:
	map<dpTree, bool> hash;
public:
	bool cover(TreeNode* parent, TreeNode* child){
		if(parent == NULL || child == NULL) return false;
		dpTree state = {parent, child};
		if(hash.find(state) != hash.end()){
			return hash[state];
		}

		if(parent == NULL){
			hash[state] = false;
			return false;
		}
		if(parent == child){
			hash[state] = true;
			return true;
		}
		return cover(parent->left, child) || cover(parent->right, child);
	}

	bool commonAncestor(TreeNode* cur, TreeNode* p, TreeNode* q){
		if(cur == p || cur == q){
			return true;
		}

		if((cover(cur->right, p) && cover(cur->left, q) ) || (cover(cur->right, q) && cover(cur->left, p)) ){
			return true;
		}else{
			return false;
		}
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == NULL){
    		return NULL;
    	}
    	
    	if(!cover(root, p) || !cover(root, q)){
    		return NULL;
    	}

    	queue<TreeNode*> que;
    	que.push(root);
    	while(!que.empty()){
    		TreeNode* cur = que.front();
    		que.pop();
    		if(cur == NULL) continue;
    		if(commonAncestor(cur, p, q)){
    			return cur;
    		}
    		que.push(cur->right);
    		que.push(cur->left);
    	}
    	return NULL;
    }
};
