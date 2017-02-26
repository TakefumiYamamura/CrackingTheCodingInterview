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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* sentinelOdd = new ListNode(-1);
        ListNode* sentinelEven = new ListNode(-1);
        ListNode* oddTail = sentinelOdd;
        ListNode* evenTail = sentinelEven;

        ListNode* cur = head;
        int i == 0;
    	while(cur != NULL){
    		if(i % 2 == 0){
    			oddTail->next = new ListNode(cur->val);
                oddTail = oddTail->next;
    		}else{
                evenTail->next = new ListNode(cur->val);
                evenTail = evenTail->next;
            }
            ListNode *next = cur->next;
            delete cur;
            cur = next;
            i++;
    	}
    	oddTail->next = sentinelEven->next;
    	return sentinelOdd->next;
    }
};