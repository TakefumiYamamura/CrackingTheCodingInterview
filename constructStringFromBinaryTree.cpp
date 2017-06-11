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
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        TreeNode* l = t->left;
        TreeNode* r = t->right;
        string ans = "";
        ans += to_string(t->val);
        if(l != NULL || r != NULL) ans += "(" + tree2str(l) + ")";
        if(r != NULL) ans += "(" + tree2str(r) + ")";
        return ans;
    }
};
