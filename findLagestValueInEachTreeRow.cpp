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
    unordered_map<int, int> um;
    vector<int> ans;
public:
    void recursive(TreeNode* cur, int depth) {
        if(cur == NULL) return;
        recursive(cur->left, depth + 1);
        recursive(cur->right, depth + 1);
        if(um.find(depth) == um.end()) um[depth] = cur->val;
        um[depth] = max(um[depth], cur->val);
    }
    vector<int> largestValues(TreeNode* root) {
        recursive(root, 0);
        for(int i = 0; um.find(i) != um.end(); i++){
            ans.push_back(um[i]);
        }
        return ans;
    }
};