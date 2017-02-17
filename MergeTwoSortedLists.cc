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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* sentinel = new ListNode(-1);
    	ListNode* tail = sentinel;
    	while(l1 && l2){
    		if(l1->val < l2->val){
    			tail->next = l1;
    			l1 = l1->next;
    		}else{
    			tail->next = l2;
    			l2 = l2->next;
    		}
    		tail = tail->next;
    	}
    	if(l1 == NULL && l2 == NULL) return sentinel->next;
    	if(l1 == NULL){
    		tail->next = l2;
    	}else if(l2 == NULL){
    		tail->next = l1;
    	}
    	return sentinel->next;
    }
};