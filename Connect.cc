/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<pair<TreeLinkNode*, int> > q;
        q.push(make_pair(root, 0));
        TreeLinkNode* sentinel = new TreeLinkNode(-1);
        pair<TreeLinkNode*, int> before = make_pair(sentinel, -1);
        while(!q.empty()){
            pair<TreeLinkNode*, int> cur = q.front();
            q.pop();
            int cur_depth = cur.second;
            if(cur.first == NULL) continue;
            q.push(make_pair(cur.first->left, cur_depth + 1));
            q.push(make_pair(cur.first->right, cur_depth + 1));
            if(before.second == cur.second) before.first->next = cur.first;
            before = cur;
        }
    }
};
