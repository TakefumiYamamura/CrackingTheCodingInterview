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
    void recursive(ListNode* start, ListNode* end){
        ListNode* cur = start;
        if(cur == NULL) return; 
        if(start == end){
            start->next = NULL;
            return;
        }

        ListNode* next_start = start->next;
        ListNode* next_end = new ListNode(-1);
        while(cur != NULL){
            if(cur->next == end){
                next_end = cur;
                if(next_end == start) return;
                start->next = next_end;
                next_end->next = next_start;
                recursive(next_start, next_end);
                return;
            }
            cur = cur->next;
        }
        return;
    }
    void reorderList(ListNode* head) {
        ListNode* cur = head;

        recursive(head, NULL);
    }
};
