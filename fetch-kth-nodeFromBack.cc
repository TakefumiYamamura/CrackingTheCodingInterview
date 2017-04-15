#include <iostream>
#include <assert.h>
using namespace std;


template<typename T>
struct ListNode{
	T value;
	ListNode<T>* next;
	ListNode(T _value): value(_value){ next = NULL;}
};


template<typename T>
class List
{
private:
	ListNode<T> *head;

public:
	List(){
		head = NULL;
	}
	~List(){
		ListNode<T> *cur = head;
		while(cur != NULL){
			ListNode<T> *prev = cur;
			cur = cur->next;
			delete prev;
		}
	}

	List(T val){
		head = ListNode<T>(val); 
	}

	ListNode<T>* tail(){
		ListNode<T>* cur = head;
		while(cur != NULL && cur->next != NULL){
			cur = cur->next;
		}
		return cur;
	}

	void append(T val){
		ListNode<T>* t = tail();
		ListNode<T>* newNode = new ListNode<T>(val);
		cout << newNode->value << endl;
		if(t == NULL){
			head = newNode;
		}else{
			t->next = newNode;
		}
	}

	T returnKthToLast(int k){
		ListNode<T>* p1 = head;
		ListNode<T>* p2 = head;
		for (int i = 0; i < k; ++i)
		{
			assert(p1 != NULL);
			p1 = p1->next;
		}

		while(p1->next != NULL){
			assert(p1 != NULL);
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2->value;
	}

	void dump(){
		ListNode<T>* cur = head;
		while(cur != NULL){
			cout << cur->value << "->";
			cur = cur->next;
		}
		cout << "NULL" << endl;
	}

};


int main(){
	List<int> list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	list.dump();

	cout << list.returnKthToLast(2) << endl;
	cout << list.returnKthToLast(3) << endl;
	cout << list.returnKthToLast(1) << endl;
	cout << list.returnKthToLast(100) << endl;
}
