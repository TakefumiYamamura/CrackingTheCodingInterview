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
    ListNode* reverseList(ListNode* head) {
        ListNode* before = NULL;
        ListNode* cur = head;
        while(cur != NULL){
          ListNode* next = cur->next;
          cur->next = before;
          before = cur;
          cur = next;
        }
        return before;
    }
};
