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
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* sentinel = new ListNode(-1);
    	sentinel->next = head;
    	ListNode* before = head;
    	if(before == NULL) return NULL;
    	ListNode* cur = head->next;
    	while(cur != NULL){
    		if(before->val == cur->val){
    			before->next = cur->next;
    			delete cur;
    			cur = before->next;
    		}else{
    			before = before->next;
    			cur = cur->next;
    		}
    	}
        return sentinel->next;
    }
};