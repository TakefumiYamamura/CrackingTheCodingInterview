/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>

class Solution {
public:
	bool traverse(TreeNode* node, TreeNode* minN, TreeNode* maxN){
		if(node == NULL) return true;
		if(maxN != NULL && maxN->val <= node->val){
			return false;
		}
		if(minN != NULL && minN->val >= node->val){
			return false;
		}
		TreeNode* updateMinN;
		TreeNode* updateMaxN;

		if(maxN == NULL){
			updateMaxN = node;
		}else if(maxN->val < node->val){
			updateMaxN = maxN; 
		}else{
			updateMaxN = node;
		}

		if(minN == NULL){
			updateMinN = node;
		}else if(minN->val > node->val){
			updateMinN = minN; 
		}else{
			updateMinN = node;
		}
		return traverse(node->left, minN, updateMaxN) && traverse(node->right, updateMinN, maxN);
	}

    bool isValidBST(TreeNode* root) {
    	return traverse(root, NULL, NULL);
    }
};