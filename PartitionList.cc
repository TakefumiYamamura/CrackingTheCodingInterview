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
        ListNode* beforeSentinel = new ListNode(-1);
        ListNode* afterSentinel = new ListNode(-1);
        ListNode* beforeTail = beforeSentinel;
        ListNode* afterTail = afterSentinel;

        ListNode* cur = head;
        while(cur != NULL){
            if(cur->val < x){
                beforeTail->next = new ListNode(cur->val);
                beforeTail = beforeTail->next;
            }else{
                afterTail->next = new ListNode(cur->val);
                afterTail = afterTail->next;
            }
            ListNode* next = cur->next;
            delete cur;
            cur = next;
        }
        beforeTail->next = afterSentinel->next;
        return beforeSentinel->next;
    }
};