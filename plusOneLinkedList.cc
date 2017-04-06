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
    bool recursive(ListNode* cur){
        if(cur == NULL) return true;
        if(recursive(cur->next)){
            cur->val += 1;
        }
        if(cur->val >= 10){
            cur->val %= 10;
            return true;
        }else{
            return false;
        }
    }
    ListNode* plusOne(ListNode* head) {
        ListNode* sentinel = new ListNode(-1);
        if(recursive(head)){
            sentinel->next = new ListNode(1);
            sentinel->next->next = head;
        }else{
            sentinel->next = head;
        }
        return sentinel->next;
    }
};  
