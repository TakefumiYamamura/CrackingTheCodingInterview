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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* cur = head;
    	ListNode* pre = NULL;
    	ListNode* top = head; 
    	while(cur != NULL){
    		if(pre == NULL){
    			if(cur->val == val){
    				delete top;
    				top = cur->next;
    				cur = cur->next;
    			}else{
    				pre = cur;
    				cur = cur->next;
    			}
    		}else{
    			if(cur->val == val){
    				pre->next = cur->next;
    				delete cur;
    				cur = pre->next;
    			}else{
    				pre = cur;
    				cur = cur->next;
    			}
    		}
    	}
    	return top;
    }
};