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
	int ans;
public:
	int recursive(TreeNode* cur){
		if(cur == NULL){
			return 0;
		}
		int r = recursive(cur->left);
		int l = recursive(cur->right);
		r = r < 0 ? 0 : r;
		l = l < 0 ? 0 : l; 
		ans = max(ans, r + l + cur->val);
		return cur->val + max(r, l);
	}
    int maxPathSum(TreeNode* root) {
    	ans = INT_MIN;
    	recursive(root, 0);
    	return ans;
    }
};
