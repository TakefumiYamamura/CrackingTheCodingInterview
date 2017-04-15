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
    void reverse(ListNode* start, ListNode* end){
        ListNode* before = start;
        ListNode* cur = start->next;
        start->next = end;
        while(cur != end->next){
            ListNode* next = cur->next;
            cur->next = before;
            before = cur;
            cur = next;
        }
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
