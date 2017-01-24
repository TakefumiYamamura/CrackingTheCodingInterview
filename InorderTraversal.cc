/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/
void print(node *n){
	cout << n->data << " ";
}

void inOrder(node *root) {
	if(root == NULL) return;
	inOrder(root->left);
	print(root);
	inOrder(root->right);
}
