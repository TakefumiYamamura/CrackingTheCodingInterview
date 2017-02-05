#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* makeNode(int num){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode*));
	node->val = num;
	return node;
}

TreeNode* testFunc(int i){
	if(i == 0) return NULL;
	TreeNode* node = new TreeNode(5);
	// TreeNode* node = makeNode(5);

	cout << node->val << endl;
	node->right = testFunc(i-1);
	return node;
}

int main(){
	// testFunc(3);
	vector<int> test;
	test.push_back(1);
	auto itr = lower_bound(test.begin(), test.end(), 1);
	cout << *itr << endl;

}
