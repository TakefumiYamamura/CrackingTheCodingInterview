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
	int cnt;

public:
	//from root to the any node.
	int countPathSum(TreeNode* root, int sum){
		int cnt = 0;
		if(root == NULL) return cnt;
		if(root->val == sum) cnt++;
		cnt += countPathSum(root->left, sum - root->val);
		cnt += countPathSum(root->right, sum - root->val);
		return cnt;
	}
    int pathSum(TreeNode* root, int sum) {
    	if(root == NULL) return 0;
    	int totalCnt = 0;
    	totalCnt += countPathSum(root, sum);
    	totalCnt += pathSum(root->left, sum);
    	totalCnt += pathSum(root->right, sum);
    	return totalCnt;
    }
};