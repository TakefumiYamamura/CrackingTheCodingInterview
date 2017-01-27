#include <iostream>

using namespace std;

void ReversePrint(Node *head){
	if(head == NULL){
		return;
	}
	ReversePrint(head->next);
	cout << head->data << endl;
}
