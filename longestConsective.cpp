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
	TreeNode *pre;
	unordered_map<TreeNode*, int> um;
	int max_v;
public:
	void recursive(TreeNode* cur){
		if(cur == NULL) return;
		if(pre == NULL){
			um[cur] = 1;
		}else{
			if(pre->val + 1 == cur->val){
				um[cur] = um[pre] + 1;
			}else{
				um[cur] = 1;
			}
		}
		pre = cur;
		recursive(cur->left);
		pre = cur;
		recursive(cur->right);
		max_v = max(max_v, um[cur]);
	}

    int longestConsecutive(TreeNode* root) {
    	pre = NULL;
    	um[root] = 1;
    	recursive(root);
    	return max_v;
    }
};
