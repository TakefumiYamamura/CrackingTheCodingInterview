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
	bool ans;
	ListNode* tmp;
	bool recursive(ListNode* cur){
		if(cur == NULL) return true;
		bool isPal = recursive(cur->next) && (cur->val == tmp->val);
		tmp = tmp->next;
		return isPal;
	}
    bool isPalindrome(ListNode* head) {
    	tmp = head;
    	return check(head);
    }
};