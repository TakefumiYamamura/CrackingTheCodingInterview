/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

class Solution {
private:
	map<TreeNode*, int> hash;
	bool check;
public:
	int setHeight(TreeNode* par){
		if(par == NULL) return 0;
		if(hash.find(par) != hash.end()){
			return hash[par];
		}
		hash[par] = max(setHeight(par->left), setHeight(par->right)) + 1;
		return hash[par];  
	}

	int fetchHeight(TreeNode* cur){
		if(cur == NULL) return 0;
		return hash[cur]; 
	}

	void traverse(TreeNode* par){
		if(par == NULL) return;

		if(abs(fetchHeight(par->right) - fetchHeight(par->left)) > 1){
			check = false;
			return;
		}

		traverse(par->right);
		traverse(par->left);

	}

    bool isBalanced(TreeNode* root) {
    	setHeight(root);
    	check = true;
    	traverse(root);
    	return check;
    }
};
