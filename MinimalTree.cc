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
	TreeNode* recursive(vector<int>& nums, int left, int right){
		if(left > right) return NULL;
		int mid = (left + right)/2;
		TreeNode* node = new TreeNode(nums[mid]);
		// TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		// node->val = nums[mid];
		if(left == right) return node;
		node->left = recursive(nums, left, mid -1);
		node->right = recursive(nums, mid + 1, right);
		return node;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
    	TreeNode* root = recursive(nums, 0, nums.size()-1);
    	return root;
    }
};
