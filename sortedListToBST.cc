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
		if(head == NULL) return NULL;
		if(head == tail) return NULL;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast && fast->next){
			if(fast == tail || fast->next == tail) break;
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* middle = new TreeNode(slow->val);
		middle->left = fetchMiddle(head, slow);
		middle->right = fetchMiddle(slow->next, tail);
		return middle;
	}

    TreeNode* sortedListToBST(ListNode* head) {
    	length = fetchLength(head);
    	TreeNode* top = fetchMiddle(head, NULL);
    	return top;
    }

};
