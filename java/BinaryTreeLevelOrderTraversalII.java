/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> que = new LinkedList<>();
        List<List<Integer>> res = new LinkedList<>();
        
        if (root == null) return res;
        que.add(root);
        while (!que.isEmpty()) {
            int n = que.size();
            List<Integer> row = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode tmp = que.poll();
                row.add(tmp.val);
                if (tmp.left != null) que.add(tmp.left);
                if (tmp.right != null) que.add(tmp.right);
            }
            res.add(0, row);
        }

        return res;
    }
}
