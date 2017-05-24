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
    int ans;
public:
    void recursive(TreeNode* cur, string sum){
        if(cur == NULL){
            return;
        }
        sum += to_string(cur->val);
        if(cur->left == NULL && cur->right == NULL){
            ans += stoi(sum);
        }
        recursive(cur->left, sum);
        recursive(cur->right, sum);
        
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        recursive(root, "");
        return ans;
    }
};