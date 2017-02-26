/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    	ListNode* next = node->next;
    	if(node == NULL) return;
    	if(next == NULL){
    		node = NULL;
    		return;
    	}
    	node->val = next->val;
    	node->next = next->next;
    	delete next;
    	return;
    }
};
