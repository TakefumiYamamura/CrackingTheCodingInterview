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
    bool mirror(TreeNode* n1, TreeNode* n2) {
        if(n1 == NULL || n2 == NULL) return (n1 == n2);
        if(n1->val != n2->val) return false;
        return mirror(n1->left, n2->right) && mirror(n1->right, n2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return (root == NULL) || mirror(root->left, root->right);
    }
};
