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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return false;
        }
        ListNode* n1 = head->next;
        ListNode* n2 = head->next->next;
        while(!(n1 == NULL && n2 == NULL)){
            if(n1 == n2) return true;
            if(n1 != NULL) n1 = n1->next;
            if(n2 != NULL){
                if(n2->next == NULL) return false;
                n2 = n2->next->next;
            }
        }
        return false;
    }
    ListNode* startLoop(ListNode *head){
        assert(hasCycle(head));
        ListNode* n1 = head->next;
        ListNode* n2 = head->next->next;
        while(true){
            if(n1 == n2) break;
            n1 = n1->next;
            n2 = n2->next->next;
        }
        ListNode* n3 = head;
        while(true){
            if(n1 == n3) break;
            n1 = n1->next;
            n3 = n3->next;
        }
        return n3;
    }
};
