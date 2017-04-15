/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// stackで解く場合には次に小さい要素が常にノードの右下にある木の一番左下に存在することを使う。

class BSTIterator {
private:
   	queue<TreeNode*> tree_queue;
public:
    BSTIterator(TreeNode* root) {
    	set_stack(root);
    }

    void set_stack(TreeNode* cur){
    	if(cur == NULL) return;
    	set_stack(cur->left);
    	tree_queue.push(cur);
    	set_stack(cur->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	return !tree_queue.empty();
    }

    /** @return the next smallest number */
    int next() {
    	if(hasNext()){
    		TreeNode* ans = tree_queue.front();
    		tree_queue.pop();
    		return ans->val;
    	}else{
    		return -1;
    	}
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */