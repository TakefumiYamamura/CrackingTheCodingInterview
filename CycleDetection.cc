/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include<map>

bool has_cycle(Node* head) {
    map<Node*, bool> hash;
    if(head == NULL) return false;
    Node* next = head;
    while(next != NULL){
        if(hash[next] == true) return true;
        hash[next] = true;
        next = next->next;
    }
    return false;
    // Complete this function
    // Do not write the main method
}
