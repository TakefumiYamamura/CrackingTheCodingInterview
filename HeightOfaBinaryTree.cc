#include <iostream>
#include <queue>

// struct node
// {
// 	int data;
// 	node* right;
// 	node* left;

// };

using namespace std;

struct nodeWithDepth
{
	node n;
	int depth;
};

int getHeight(Node* root){
	vector<nodeWithDepth> q;
	nodeWithDepth tmp = {*root, 0};
	q.push(tmp);
	while(!q.empty()){
		nodeWithDepth cur = q.front();
		q.pop();
		if(cur->right)

		q.push(cur->left)
		q.push(cur->right)
	}


}
