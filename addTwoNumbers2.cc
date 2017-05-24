/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	stack<int> stack1;
	stack<int> stack2;
	stack<int> ans_stack;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    	ListNode* cur1 = l1;
    	ListNode* cur2 = l2;
    	while(cur1 != NULL){
    		stack1.push(cur1->val);
    		cur1 = cur1->next;
    	}

    	while(cur2 != NULL){
    		stack2.push(cur2->val);
    		cur2 = cur2->next;
    	}

    	bool carry = false;
    	while(!stack1.empty() || !stack2.empty()){
    		int n1 = stack1.empty() ? 0 : stack1.top();
    		if(!stack1.empty() ) stack1.pop();
    		int n2 = stack2.empty() ? 0 : stack2.top();
    		if(!stack2.empty() ) stack2.pop();
    		int n3 = n1 + n2;
    		if(carry) n3++;
    		carry = n3 >= 10 ? true : false;
    		n3 %= 10;
    		ans_stack.push(n3);
    	}
    	if(carry) ans_stack.push(1);

    	ListNode* sentinel = new ListNode(-1);
    	ListNode* cur = sentinel;
    	while(!ans_stack.empty()){
    		cur->next = new ListNode(ans_stack.top());
    		ans_stack.pop();
    		cur = cur->next;
    	}
    	return sentinel->next;
    }
};
