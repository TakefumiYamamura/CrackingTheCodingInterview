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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode* sentinel = new ListNode(-1);
    	ListNode* tail = sentinel;
    	
    	while(true){
    		int min = INT_MAX;
    		int min_index = -1;
    		for (int i = 0; i < lists.size(); ++i)
    		{
    			if(lists[i] == NULL) continue;
    			if(min > lists[i]->val){
    				min_index = i;
    				min = lists[i] = val;
    			}
    		}
    		tail->next = lists[min_index];
    		lists[min_index] = lists[min_index]->next;

    		for (int i = 0; i < lists.size(); ++i)
    		{
    			if(lists[i] != NULL) continue;
    		}
    		break;
    	}
        
    }
};
