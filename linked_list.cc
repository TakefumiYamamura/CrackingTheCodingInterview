#include <iostream>

using namespace std;

struct Node
{
	Node *next;
	int data;
};


class LinkedList {
public:
	Node *head;
	LinkedList(int data);
	~LinkedList();
	void show();
	void addEnd(int data);
	void addNth(int data, int n);
	void deleteNth(int n);
};


LinkedList::LinkedList(int data) {
	head = (struct Node *)malloc( sizeof(struct Node) );
	head->next = NULL;
	head->data = data;
}

LinkedList::~LinkedList(){

}


void LinkedList::show(){
	Node *cur = head;
	int index = 0;
	while(cur != NULL){
		cout << "index: "<< index << " value: " << cur->data << endl; 
		cur = cur->next;
		index++;
	}
	return;
}


void LinkedList::addEnd(int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node *cur = head;

	while(cur){
		if(cur->next == NULL){
			cur->next = newNode;
			return;
		}
		cur = cur->next;

	}

}

void LinkedList::addNth(int data, int n){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node *cur = head;

	int index = 0;

	if(n == 0){
		newNode->next = cur;
		head = newNode;
	}

	while(cur){
		if(cur->next == NULL){
			if(index <= n) cout << "position is excess the length of list" << endl;
			return;
		}
		if(index == n-1){
			Node *tmpNode = new Node;
			tmpNode = cur->next;
			cur->next = newNode;
			newNode->next = tmpNode;
		}
		index++;
		cur = cur->next;
	}

}

void LinkedList::deleteNth(int n){
	Node *cur = head;

	if(n == 0){
		Node *tmp = new Node;
		tmp = head->next;
		delete head;
		head = tmp;
	}

	int index = 0;

	while(cur){
		if(cur->next == NULL){
			if(index <= n) cout << "position is excess the length of list" << endl;
			return;
		}
		if(index == n-1){
			Node *tmpNode = new Node;
			tmpNode = cur->next;
			if(cur->next->next != NULL) cur->next = cur->next->next;
			delete(tmpNode);
		}
		index++;
		cur = cur->next;
	}

}


int main(){
	LinkedList list = LinkedList(10);
	list.addEnd(20);
	list.addEnd(30);
	list.addEnd(40);
	list.show();
	cout << "----------------" << endl;
	list.addNth(100, 2);
	list.show();
	cout << "----------------" << endl;
	list.addNth(0,0);
	list.show();
	cout << "----------------" << endl;
	list.deleteNth(2);
	list.show();

}





