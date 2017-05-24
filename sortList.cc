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
	int count_size(ListNode *node){
		int count = 0;
		ListNode *cur = node;
		while(cur != NULL){
			count++;
			cur = cur->next;
		}
	}
    ListNode* sortList(ListNode* head) {
    	int len = count_size(head);
    	int block = 1;

    	return head;
        
    }
};