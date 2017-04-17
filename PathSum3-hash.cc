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
    int target;
    unordered_map<int, int> hash;
public:
    void recursive(TreeNode* root, int cur){
        if(root == NULL) return;
        cur += root->val;
        ans += hash[cur - target];
        hash[cur]++;
        recursive(root->left, cur);
        recursive(root->right, cur);
        hash[cur]--;
    }
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        target = sum;
        hash[0]++;
        recursive(root, 0);
        return ans;
    }
};