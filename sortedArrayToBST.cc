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
	vector<int> shared_nums;
public:
	TreeNode* recursive(int l, int r){
		if(l > r) return NULL;
		int mid = (l + r)  / 2;
		TreeNode* cur = new TreeNode(shared_nums[mid]);
		cur->left = recursive(l, mid-1);
		cur->right = recursive(mid+1, r);
		return cur;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	shared_nums = nums;
    	int size = nums.size();
    	TreeNode* head =  recursive(0, size - 1);
    	return head; 
    }
};
