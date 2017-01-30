struct Node
{
   int data;
   struct Node *next;
};

void DeleteMiddleNode(Node *n)
{
    Node tmpN = n;
    n = n->next;
    delete tmpN;
}
