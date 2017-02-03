#include <iostream>
using namespace std;
struct Node
{
    int data;
   Node* next;
};

Node* InsertNth(Node *head, int data, int position)
{
  int cnt = 0;
  Node* beforeNode;
  Node* newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  Node* tmp = head;
  if(position == 0){
    newNode->next = head;
    return newNode;
  }
  while(cnt != position){
    beforeNode = tmp;
    if(tmp->next != NULL){
      tmp = tmp->next;
      newNode->next = tmp;
    }
    cnt++;
  }
  beforeNode->next = newNode;
  return head;
}

//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second){
	Node *runner1 = first;
	Node *runner2 = second;
	Node *cur = (Node *)malloc(sizeof(Node));
	Node *top = (Node *)malloc(sizeof(Node));
	int carry = 0;
	bool firstFlag = true;
	while(!(runner1 == NULL && runner2 == NULL) ){
		int tmp = 0;
		if(runner1 != NULL){
			tmp += runner1->data;
			runner1 = runner1->next;
		}
		if(runner2 != NULL){
			tmp += runner2->data;
			runner2 = runner2->next;
		}
		tmp += carry;
		carry = tmp - tmp % 10;
		carry /= 10;
		Node *newN = (Node *)malloc(sizeof(Node));
		newN->data = tmp % 10;
		newN->next = (Node *)malloc(sizeof(Node));
		cur = newN;
		if(firstFlag) top = cur;
		firstFlag = false;
		cout << newN->data << endl;
		cur = cur->next;
	}
	if(carry == 1){
		Node *newN = (Node *)malloc(sizeof(Node));
		newN->data = carry;
		cur = newN;
	}
	return top;
}

Node* Insert(Node *head,int data)
{
    Node* newN = (Node *)malloc(sizeof(Node));
    newN->data = data;
    newN->next = NULL;

    if(head == NULL){
      // cout << newN->data << " --> NULL" << endl;
      head = newN;
      return head;
    }
    newN->next = head;
    head = newN;
    return head;
}

void Print(Node *head){

	if(head == NULL){
		return;
	}
	cout << head->data << endl;
	Print(head->next);
}

void ReversePrint(Node *head){
	if(head == NULL){
		return;
	}
	ReversePrint(head->next);
	cout << head->data << endl;
}


int main(){
	Node *head1 = (Node *)malloc(sizeof(Node));
	Node *head2 = (Node *)malloc(sizeof(Node));
	head1 = NULL;
	head2 = NULL;
	head1 = Insert(head1, 5);
	head1 = Insert(head1, 6);
	head1 = Insert(head1, 3);
	head2 = Insert(head2, 8);
	head2 = Insert(head2, 4);
	head2 = Insert(head2, 2);
	// ReversePrint(head1);
	// ReversePrint(head1);
	Print(head1);
	Print(head2);
	Node *newH = addTwoLists(head1, head2);
	// Print(newH);
	// ReversePrint(newH);

}