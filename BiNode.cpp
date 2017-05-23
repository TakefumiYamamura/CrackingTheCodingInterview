#include <iostream>

using namespace std;

struct BiNode {
	int val;
	BiNode *node1;
	BiNode *node2;
	BiNode(int x) : val(x), node1(NULL), node2(NULL) {}
};

class Solver
{
public:
	BiNode* before;
	BiNode* top;

	Solver(BiNode* top_){
		before = NULL;
		top = NULL;
	}

	void change(BiNode* root){
		if(root == NULL) return;
		BiNode* left = root->node1;
		BiNode* right = root->node2;
		change(left);
		if(before != NULL){
			before->node2 = root;
			root->node1 = before;
		}else{
			top = root;
		}
		before = root;
		change(right);
	}

};


int main(){
	BiNode *root = new BiNode(4);
	root->node1 = new BiNode(2);
	root->node2 = new BiNode(5);
	root->node1->node1 = new BiNode(1);
	root->node1->node1->node1 = new BiNode(0);
	root->node1->node2 = new BiNode(3);
	root->node2->node2 = new BiNode(6);
	Solver s = Solver(root);
	s.change(root);
	BiNode *cur = s.top;
	while(cur != NULL) {
		cout << cur->val << " ";
		cur = cur->node2;
	}
	cout << endl;
}

