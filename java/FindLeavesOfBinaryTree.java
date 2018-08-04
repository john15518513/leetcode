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
    
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        helper(root, res);
        return res;
    }
    
    private int helper(TreeNode root, List<List<Integer>> res) {
        if (root == null) {
            return 0;
        }
        
        int height = Math.max(helper(root.left, res), helper(root.right, res)) + 1;
        if (height - 1 >= res.size()) {
            res.add(new ArrayList<>());
        }
        res.get(height-1).add(root.val);
        root.left = root.right = null;
        
        return height;
    }
}
