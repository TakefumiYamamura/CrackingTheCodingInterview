#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
struct Node
{
	T val;
	int count;
	Node<T>* left;
	Node<T>* right;
	Node(T _val, int _count) : val(_val), count(_count), left(NULL), right(NULL) {}
};


template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	
	void track(T x){
		if(root == NULL){
			root = new Node<T>(x, 0);
		}else{
			Node<T>* cur = root;
			Node<T>* before;
			while(cur != NULL){
				before = cur;
				if(cur->val <= x){
					cur = cur->right;
				}else if (cur->val > x){
					cur->count += 1; 
					cur = cur->left;
				}
			}

			if(before->val <= x){
				before->right = new Node<T>(x, 0);
			}else{
				before->left = new Node<T>(x, 0);
			}
		}
	}

	int getRankOfNumber(T x){
		Node<T>* cur = root;
		int index = 0;
		while(cur != NULL){
			if(cur->val == x) return index + cur->count;
			if(cur->val <= x){
				index += cur->count + 1;
				cur = cur->right;
			}else{
				cur = cur->left;
			}
		}
		return -1;
	}
};

int main(){
	BinarySearchTree<int> bst = BinarySearchTree<int>();
	bst.track(5);
	cout << bst.getRankOfNumber(5) << endl;
	bst.track(1);
	cout << bst.getRankOfNumber(5) << endl;
	bst.track(4);
	bst.track(4);
	bst.track(5);
	bst.track(9);
	bst.track(7);
	bst.track(13);
	bst.track(3);

	cout << bst.getRankOfNumber(5) << endl;

	cout << bst.getRankOfNumber(9) << endl;
	cout << bst.getRankOfNumber(1) << endl;
	cout << bst.getRankOfNumber(3) << endl;
	cout << bst.getRankOfNumber(4) << endl;



}

