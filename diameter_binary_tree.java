/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    int ans = 0;
    private int recursive(TreeNode cur){
        if(cur == null) return 0;
        int l = recursive(cur.left);
        int r = recursive(cur.right);
        ans = Math.max(ans, l + r);
        
        return Math.max(l, r) + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        recursive(root);
        return ans;
    }
}
