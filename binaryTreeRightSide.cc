/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node
{
  TreeNode* node;
  int depth;
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      if(root == NULL) return ans;
      Node before = {root, 0};
      queue<Node> q;
      q.push(before);
      int last = 0;
      while(!q.empty()){
        Node cur = q.front();
        q.pop();
        if(cur.node == NULL) continue;
        last = cur.node->val;
        if(cur.depth != before.depth){
          ans.push_back(before.node->val);
        }
        Node n1 = {cur.node->left, cur.depth + 1};
        Node n2 = {cur.node->right, cur.depth + 1};
        q.push(n1);
        q.push(n2);
        before = cur;
      }
      ans.push_back(last);

      return ans;
    }
};
