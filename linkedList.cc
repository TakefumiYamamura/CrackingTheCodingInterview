#include <iostream>

using namespace std;


template < typename T >
struct Node
{
	Node<T> *next;
	T data;
};

template < typename T >
class LinkedList {
public:
	Node<T> *head;
	LinkedList(T data);
	~LinkedList();
	void show();
	void addEnd(T data);
	void addNth(T data, int n);
	void deleteNth(int n);
};

template < typename T >
LinkedList<T>::LinkedList(T data) {
	head = (struct Node<T> *)malloc( sizeof(struct Node) );
	head->next = NULL;
	head->data = data;
}

template < typename T >
LinkedList<T>::~LinkedList(){

}


void LinkedList<T>::show(){
	Node<T> *cur = head;
	int index = 0;
	while(cur != NULL){
		cout << "index: "<< index << " value: " << cur->data << endl; 
		cur = cur->next;
		index++;
	}
	return;
}


void LinkedList<T>::addEnd(T data){
	Node<T> *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node<T> *cur = head;

	while(cur){
		if(cur->next == NULL){
			cur->next = newNode;
			return;
		}
		cur = cur->next;

	}

}

void LinkedList<T>::addNth(T data, int n){
	Node<T> *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node<T> *cur = head;

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
			Node<T> *tmpNode = new Node;
			tmpNode = cur->next;
			cur->next = newNode;
			newNode->next = tmpNode;
		}
		index++;
		cur = cur->next;
	}

}

void LinkedList<T>::deleteNth(int n){
	Node *cur = head;

	if(n == 0){
		Node<T> *tmp = new Node;
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
			Node<T> *tmpNode = new Node;
			tmpNode = cur->next;
			if(cur->next->next != NULL) cur->next = cur->next->next;
			delete(tmpNode);
		}
		index++;
		cur = cur->next;
	}

}


int main(){
	LinkedList<int> list = LinkedList(10);
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