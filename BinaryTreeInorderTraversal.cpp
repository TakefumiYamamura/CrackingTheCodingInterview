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
    vector<int> ans;
public:
    void recursive(TreeNode* cur) {
        if(cur == NULL) return;
        recursive(cur->left);
        ans.push_back(cur->val);
        recursive(cur->right);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        recursive(root);
        return ans;
    }
};
