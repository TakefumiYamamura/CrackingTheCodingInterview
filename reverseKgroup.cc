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
     void reverse(ListNode* before_sec, ListNode* sec_end){
        ListNode* before = before_sec;
        ListNode* sec_start = before_sec->next;
        ListNode* cur = sec_start;
        ListNode* after_sec = sec_end->next;
        while(cur != after_sec){
            ListNode* next = cur->next;
            cur->next = before;
            before = cur;
            cur = next;
        }
        sec_start->next = after_sec;
        before_sec->next = sec_end;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;

        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* cur = head;
        ListNode* before = sentinel;
        int count = 1;
        while(cur != NULL){
            if(count == k){
                count = 1;
                ListNode* next = cur->next;
                ListNode* next_before = before->next;
                reverse(before, cur);
                cur = next;
                before = next_before;
            }else{
                cur = cur->next;
                count++;
            }
        }
        return sentinel->next;
    }
};
