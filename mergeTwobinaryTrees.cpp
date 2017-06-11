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
public:

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    	if(t1 == NULL && t2 == NULL) return NULL;
		int sum = 0;
		if(t1 != NULL) sum += t1->val;
		if(t2 != NULL) sum += t2->val;
		TreeNode* ans =  new TreeNode(sum);
		TreeNode* t1l = t1 == NULL ? NULL : t1->left;
		TreeNode* t2l = t2 == NULL ? NULL : t2->left;
		ans->left = mergeTrees(t1l, t2l);
		TreeNode* t1r = t1 == NULL ? NULL : t1->right;
		TreeNode* t2r = t2 == NULL ? NULL : t2->right;
		ans->right = mergeTrees(t1r, t2r);
		return ans;
    }
};