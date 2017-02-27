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
    ListNode* swapPairs(ListNode* head) {
    	ListNode* sentinel = new ListNode(-1);
    	ListNode* tail = sentinel;
    	tail->next = head;

    	while(tail && tail->next){
    		ListNode* first = tail->next;
    		ListNode* second = tail->next->next;
    		ListNode* third = NULL;
    		if(tail->next->next) third = tail->next->next->next;
    		tail->next = second;
    		tail->next->next = first;
    		tail->next->next->next = third;
    		tail = first;
    	}
    	return sentinel->next;
    }
};