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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* sentinel = new ListNode(-1);
    	ListNode* tail = sentinel;
    	int tmp = 0;
    	while(l1 != NULL && l2 != NULL){
    		ListNode* newNode = new ListNode((l1->val + l2->val + tmp) % 10);
    		tail->next = newNode;
    		tail = tail->next;
    		if(l1->val + l2-> val + tmp >= 10){
    			tmp = 1;
    		}else{
    			tmp = 0;
    		}
    		l1 = l1->next;
    		l2 = l2->next;
    	}
    	while(l1 != NULL){
    		ListNode* newNode = new ListNode((l1->val + tmp) % 10);
    		tail->next = newNode;
    		tail = tail->next;
    		if(l1->val +tmp >= 10){
    			tmp = 1;
    		}else{
    			tmp = 0;
    		}
    		l1 = l1->next;
    	}

    	while(l2 != NULL){
    		ListNode* newNode = new ListNode((l2->val + tmp) % 10);
    		tail->next = newNode;
    		tail = tail->next;
    		if(l2->val + tmp >= 10){
    			tmp = 1;
    		}else{
    			tmp = 0;
    		}
    		l2 = l2->next;
    	}

    	if(tmp == 1){
    		ListNode* newNode = new ListNode(1);
    		tail->next = newNode;
    	}
    	return sentinel->next;
        
    }
};