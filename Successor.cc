/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
// 	TreeNode* searchMostLeft(TreeNode* node){
// 		assert(node != NULL);
// 		if(node->left == NULL) return node;
// 		return searchMostLeft(node->left);
// 	}

//     TreeNode* inorderSuccessor(TreeNode* p) {
//     	if(p == NULL){
//     		return NULL;
//     	}
//     	if(p->right != NULL){
//     		return searchMostLeft(p->right);
//     	}
//     	TreeNode* cur = p;
//     	while(cur->parent != NULL){
//     		if(cur->parent->left == cur){
//     			return cur->parent;
//     		}
//     		cur = cur->parent;
//     	}
//     	return NULL;
//     }
// };

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	if(p == NULL || root == NULL){
    		return NULL;
    	}
    	TreeNode *ans = NULL;
    	TreeNode *cur = root;
    	while(cur != NULL){
    		if(cur->val > p->val){
    			ans = cur;
    			cur = cur->left;
    		}else{
    			cur = cur->right;
    		}
    	}
    	return ans;
    }
};
