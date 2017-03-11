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
    int countNodes(TreeNode* root) {
    	int ans = 0;
    	queue<TreeNode*> q;
    	q.push(root);
        while(!q.empty()){
        	TreeNode* cur = q.front();
        	q.pop();
        	if(cur == NULL) continue;
        	ans++;
        	q.push(cur->left);
        	q.push(cur->right);
        }
        return ans;
    }
};