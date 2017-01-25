#include <iostream>

// struct node
// {
// 	int data;
// 	node* right;
// 	node* left;

// };

using namespace std;

void print(node *n){
	cout << n->data << " ";
}

void postOrder(node *root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	print(root);
}
