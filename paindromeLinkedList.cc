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
    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* before = NULL;
        while(cur != NULL){
            ListNode* next = cur->next;
            cur->next = before;
            before = cur;
            cur = next;
        }
        return before;
    }

    int countDepth(ListNode* head){
        int count = 0;
        ListNode* cur = head;
        while(cur != NULL){
            count++;
            cur = cur->next;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        int depth = countDepth(head);
        if(depth == 0) return true;
        ListNode* med = head;
        for (int i = 0; i < depth / 2; ++i)
        {
            med = med->next;
        }
        ListNode* p1 = head;
        ListNode* p2 = reverseList(med);
        while(p1 != NULL && p2 != NULL){
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
        
    }
};