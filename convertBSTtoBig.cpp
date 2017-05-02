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
    vector<int> array;
    unordered_map<int, int> um;
public:
    void recursive(TreeNode* root){
        if(root == NULL) return;
        array.push_back(root->val);
        recursive(root->left);
        recursive(root->right);
    }
    void set_recursive(TreeNode* root){
        if(root == NULL) return;
        root->val = array[um[root->val]];
        set_recursive(root->left);
        set_recursive(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        recursive(root);
        sort(array.begin(), array.end());
        for(int i = 0; i < array.size(); i++){
            um[array[i]] = i;
        }
        for(int i = array.size() - 2; i >= 0; i--){
            array[i] += array[i+1];
        }
        set_recursive(root);
        return root;
    }
};