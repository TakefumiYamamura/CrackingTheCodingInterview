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
	int getLength(ListNode *head){
		int count = 0;
		ListNode* tmp = head;
		while(tmp != NULL){
			tmp = tmp->next;
			count++;
		}
		return count;
	}

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int al = getLength(headA);
    	int bl = getLength(headB);
    	ListNode* tmpA = headA;
    	ListNode* tmpB = headB;
    	while(al > bl){
    		tmpA = tmpA->next;
    		al--;
    	}
    	while(al < bl){
    		tmpB = tmpB->next;
    		bl--;
    	}

    	while(tmpA != NULL && tmpB != NULL){
    		if(tmpA == tmpB) return tmpA;
    		tmpA = tmpA->next;
    		tmpB = tmpB->next;
    	}
    	return NULL;
    }
};