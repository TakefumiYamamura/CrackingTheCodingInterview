/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct BinarySearchTree{
    TreeNode root;
    TreeNode cur;
    vector<int> rest;
    BinarySearchTree(TreeNode _root, TreeNode _cur, vector<int> _rest) : root(_root), cur(_cur), rest(_rest) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        vector<int> start;
        for (int i = 0; i < n; ++i)
        {
            start.push_back(i+1);
        }
        queue<BinarySearchTree> q;
        for (int i = 0; i < start.size(); ++i)
        {
            vector<int> next = start;
            next.erase(start.begin() + i);
            TreeNode cur = TreeNode(i); 
            BinarySearchTree bst = BinarySearchTree(cur, cur, next);
            q.push(bst);
        }
        while(!q.empty()){
            BinarySearchTree cur_bst = q.front();
            q.pop();
            vector<int> cur_array = cur_bst.rest;
            if(cur_array.size() == 0){
                ans.push_back(&(cur_bst.root) );
                continue;
            }
            for (int i = 0; i < cur_array.size(); ++i)
            {
                vector<int> next_array = cur_array;
                next_array.erase(next_array.begin() + i);
                TreeNode next_cur =TreeNode(cur_array[i]);
                int cur_val = cur_bst.cur.val;
                if(cur_val < cur_array[i]){
                    cur_bst.cur.right = &next_cur;
                }else{
                    cur_bst.cur.left = &next_cur; 
                }
                BinarySearchTree bst = BinarySearchTree(cur_bst.root, next_cur, next_array);
                q.push(bst);
            }
        }
        return ans;
    }
};
