/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* deleteOdd(LinkedListNode* list) {
	if(list == NULL) return NULL;
	LinkedListNode* head = list;
	LinkedListNode* nextN = list->next;
	LinkedListNode* cur = list;
	bool flag = true;
	while(cur != NULL){
		if(cur->val % 2 == 1){
			if(cur->next == NULL){
				cur = NULL;
				break;
			}
			LinkedListNode* tmp = cur->next;
			if(flag) head  = cur->next;
			cur->val  = tmp->val;
			cur->next = tmp->next; 
			nextN = cur->next;
		}else{
			flag = false;
			cur = cur->next;
			nextN = cur->next;
		}
	}
	return head;
}

