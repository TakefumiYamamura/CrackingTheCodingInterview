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
    TreeNode* first;
    TreeNode* second;
    TreeNode* before;
public:
    void recursive(TreeNode* cur){
       if(cur == NULL) return;
       recursive(cur->left);
       if(before != NULL){
           if(before->val > cur->val){
               if(first == NULL){
                   first = before;
                   second = cur;
               } else {
                   second = cur;
               } 
           }
       }
       before = cur;
       recursive(cur->right);
    }
    void recoverTree(TreeNode* root) {
        before = NULL;
        first = NULL;
        second = NULL;
        recursive(root);
        swap(first->val, second->val);
    }
};
