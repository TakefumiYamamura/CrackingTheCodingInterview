/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
	bool haveChild(TreeNode* root, TreeNode* target){
		if(root == NULL) return false;
		// dpTree tmp = {root, target};
		// if(hash.find(tmp) != hash.end()){
		// 	return hash[tmp];
		// }
		if(root == target){
			// hash[tmp] = true;
			return true;
		}
		bool ans = haveChild(root->left, target) || haveChild(root->right, target);
		// hash[tmp] = ans;
		return ans;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		queue<TreeNode*> que;
		que.push(root);
		if(!(haveChild(cur, p) && haveChild(cur, q))){
			return NULL;
		}
		while(!que.empty()){
			TreeNode* cur = que.front();
			que.pop();
			if(cur == NULL) continue;
			if(haveChild(cur->left, p) && haveChild(cur->right, q)){
				return cur;
			}
			if(haveChild(cur->left, q) && haveChild(cur->right, p)){
				return cur;
			}
			if(cur == p || cur == q) return cur;
			if(haveChild(cur->left, p) && haveChild(cur->left, q)){
				que.push(cur->left);
			}else{
				que.push(cur->right);
			}
		}
		return NULL;
	}

};