#include <iostream>

using namespace std;

Node *newHead;

Node* Reverse(Node *head)
{
	if(head == NULL) return head;
	Node *prev = NULL;
	Node *cur = head;
	while(cur->next != NULL){
		Node *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	cur->next = prev;
	return cur;
}
