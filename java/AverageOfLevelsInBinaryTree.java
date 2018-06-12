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
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> que = new LinkedList<>();
        List<Double> res = new ArrayList<>();
        que.add(root);
        
        while (!que.isEmpty()) {
            Double sum = 0.0;
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode tmp = que.poll();
                sum += tmp.val;
                if (tmp.left != null) que.add(tmp.left);
                if (tmp.right != null) que.add(tmp.right);
            }
            res.add(sum/n);
        }
        
        return res;
    }
}
