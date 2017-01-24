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

void preOrder(node *root){
	if(root == NULL){
		return;
	}
	print(root);
	preOrder(root->left);
	preOrder(root->right);

}
