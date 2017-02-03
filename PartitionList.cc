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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = NULL;
        ListNode* beforeEnd = NULL;
        ListNode* afterHead = NULL;
        ListNode* afterEnd = NULL;
        ListNode* tmp = head;
        while(tmp != NULL){
        	if(tmp->val < x){
        		beforeEnd = tmp;
        		beforeEnd->next = (ListNode *)malloc(sizeof(ListNode));
        		if(beforeHead == NULL) beforeHead = beforeEnd;
        		beforeEnd = beforeEnd->next;
        	}else{
        		afterEnd = tmp;
        		afterEnd->next = (ListNode *)malloc(sizeof(ListNode));
        		if(afterHead = NULL) afterHead = afterEnd;
        		afterEnd = afterEnd->next;
        	}
        	tmp = tmp->next;
        }
        if(beforeEnd == NULL) return afterHead;
        beforeEnd->next = afterHead;
        return beforeHead;
    }
};
