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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* before = sentinel;
        for (int i = 0; i < n; ++i)
        {
            first = first->next;
            if(first == NULL) return NULL;
        }
        while(first == NULL){
            first = first->next;
            second = second->next;
            before = before ->next;
        }
        before->next = second->next;
        delete second;
        return sentinel->next;
    }
};
