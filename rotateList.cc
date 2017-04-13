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
    int fetchLength(ListNode* head){
        int count = 0;
        ListNode* cur = head;
        while(cur != NULL){
            cur = cur->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int length = fetchLength(head);
        if(length == 0) return NULL;
        // k = k % len;
        k = (length - k % length) % length;
        ListNode* ans_head;
        ListNode* cur = head;
        if(k == 0) return head;
        for(int count = 0; count < k-1;  count++){
            cur = cur->next;
        }

        ans_head = cur->next;
        cur->next = NULL;
        cur = ans_head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = head;
        return ans_head;
    }
};
