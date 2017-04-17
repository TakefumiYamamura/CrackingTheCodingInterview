#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val): val(_val), left(NULL), right(NULL) {}
};

bool checkSameTree(TreeNode* t1, TreeNode* t2){
	if(t1 == NULL && t2 == NULL) return true;
	if(t1 == NULL || t2 == NULL) return false;
	if(t1->val != t2->val) return false;
	return checkSameTree(t1->left, t2->left) && checkSameTree(t1->left, t2->left); 
}

// check if t2 is subTree of t1; 
bool checkSubTree(TreeNode* t1, TreeNode* t2){
	if(t1 == NULL){
		return false; // When big tree is empty, subtree is not found.
	}else if(t2 == NULL){
		return true; // Empty tree is always a subtree.
	}else if(t1->val == t2->val){
		return checkSameTree(t1, t2);
	}else{
		return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
	}
}

int main(){
	TreeNode* root1 = new TreeNode(1);
	TreeNode* root2 = new TreeNode(2);
	root2->left = new TreeNode(3);
	root2->right = new TreeNode(4);

	cout << checkSubTree(root1, root2) << endl;
	root1->right = root2;
	cout << checkSubTree(root1, root2) << endl;

}