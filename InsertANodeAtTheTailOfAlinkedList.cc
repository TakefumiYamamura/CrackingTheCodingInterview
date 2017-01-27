#include <iostream>

using namespace std;

struct Node
{
   int data;
   struct Node *next;
};

Node* Insert(Node *head,int data)
{
    Node* nextN = (Node *)malloc(sizeof(Node));
    nextN->data = data;
    nextN->next = NULL;

    if(head == NULL){
      // cout << nextN->data << " --> NULL" << endl;
      head = nextN;
      return head;
    }

    Node* tmp = head;
    // cout << tmp->data << " --> ";
    while(tmp->next != NULL){
        tmp = tmp->next;
        // cout << tmp->data << " --> ";
    }
    // cout << data << " --> NULL" << endl;

    tmp->next = nextN;

    return head;
}

// top insert
// Node* Insert(Node *head,int data)
// {
//     Node* newN = (Node *)malloc(sizeof(Node));
//     newN->data = data;
//     newN->next = NULL;

//     if(head == NULL){
//       // cout << newN->data << " --> NULL" << endl;
//       head = newN;
//       return head;
//     }
//     newN->next = head;
//     head = newN;
//     return head;
// }

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

Node* Delete(Node *head, int position)
{
  Node* nextN = head;
  Node* beforeNode, deleteNode;
  if(position == 0){
    return 
  }
  for (int i = 0; i < position; ++i)
  {
    beforeNode = nextN;
    nextN = nextN->next;
  }
  beforeNode->next = nextN;
}


int main(){
  // Node* top = Insert(NULL, 2);
  Insert(Insert(Insert(NULL, 2), 3), 5);
}
