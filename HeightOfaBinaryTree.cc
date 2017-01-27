// #include <iostream>
// #include <queue>

// struct node
// {
// 	int data;
// 	node* right;
// 	node* left;

// };

// using namespace std;


int maxDepth = 0;

void recursive(Node* cur, int depth){
	if(cur == NULL) return;
	maxDepth = max(maxDepth, depth);
	recursive(cur->left, depth+1);
	recursive(cur->right, depth+1);
}

int height(Node* root){
	recursive(root, 0);
	return maxDepth;
}
