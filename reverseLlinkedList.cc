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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* sentinel =  new ListNode(-1);
        sentinel->next = head;
        ListNode* start = sentinel;
        ListNode* end;
        ListNode* cur = sentinel;
        for (int i = 0; i < n; ++i)
        {
            if(i < m)start = cur;
            cur = cur->next;
            end = cur;
        }
        reverse(start, end);
        return sentinel->next;
    }
};
