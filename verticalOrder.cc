/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Node
{
public:
  TreeNode* node;
  int id;
  Node(TreeNode* _node, int _id){
    node = _node;
    id = _id;
  }
};

class Solution {
public:
    map<int, vector<int> > hash;
    vector<vector<int> > verticalOrder(TreeNode* root) {
        queue<Node> q;
        q.push(Node(root, 0));
        while(!q.empty()){
          Node cur = q.front();
          q.pop();
          if(cur.node == NULL) continue;
          hash[cur.id].push_back(cur.node->val);
          q.push(Node(cur.node->left, cur.id - 1));
          q.push(Node(cur.node->right, cur.id + 1));
        }
        vector<vector<int> > ans;
        for (auto itr = hash.begin(); itr != hash.end(); ++itr)
        {
          ans.push_back(itr->second);
        }
        return ans;

    }
};
