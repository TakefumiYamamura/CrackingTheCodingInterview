int isPresent(node* root, int val){
	node* cur = root;
	while(cur != NULL){
		if(cur->val == val) return 1;
		if(cur->val < val){
			cur = cur->right;
		}else{
			cur = cur->left;
		}
	}
	return 0;
}