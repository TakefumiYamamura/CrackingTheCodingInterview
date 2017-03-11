/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* fetchMiddle(ListNode* head, ListNode* tail){
		if(head == NULL) return;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast && fast->next){
			if(fast == tail || fast->next == tail) break;
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* middle = new TreeNode(slow->val);
		middle->left = fetchMiddle(head, slow);
		middle->right = fetchMiddle(slow, tail);
		return slow;
	}

    TreeNode* sortedListToBST(ListNode* head) {
    	TreeNode* top = fetchMiddle(head->val, NULL);
    	top->left = fetchMiddle()
    	return top;
    }

};