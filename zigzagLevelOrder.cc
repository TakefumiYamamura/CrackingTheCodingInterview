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
	vector<vector<int> > ans;
public:
	void recursive(TreeNode* cur,  int level){
		if(cur == NULL) return;
		if(ans.size() == level){
			vector<int> tmp;
			ans.push_back(tmp);
		}
		if(level % 2 == 0){
		    ans[level].push_back(cur->val);
		}else{
		    ans[level].insert(ans[level].begin(), cur->val);
		}
		recursive(cur->left, level + 1);
		recursive(cur->right, level + 1);
	}
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	recursive(root, 0);
    	return ans;    
    }
};