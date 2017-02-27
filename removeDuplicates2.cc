/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//     	ListNode* sentinel = new ListNode(-1);
//     	sentinel->next = head;
//     	ListNode* cur = head;
//     	unordered_map<int, int> hash;
//     	while(cur){
//     		hash[cur->val]++;
//     		cur = cur->next;
//     	}
//     	cur = head;
//     	ListNode* before = sentinel;
//     	while(cur){
//     		if(hash[cur->val] > 1){
//     			before->next = cur->next;
//     			delete cur;
//     			cur = before->next;
//     		}else{
//     			cur = cur->next;
//     			before = before->next;
//     		}
//     	}
//     	return sentinel->next;
        
//     }
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* sentinel = new ListNode(-1);
    	sentinel->next = head;
    	ListNode* cur = head;
    	ListNode* before = sentinel;

    	while(cur && cur->next){
    		if(cur->val == cur->next->val){
    			int  same_val = cur->val;
    			while(cur && same_val == cur->val){
    				ListNode* next = cur->next;
    				delete cur;
    				cur = next;
    			}
    			before->next = cur;
    		}else{
    			cur = cur->next;
    			before = before->next;
    		}
    	}
    	return sentinel->next;
        
    }
};