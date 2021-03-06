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
    
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<String>();
        if (root != null) searchBT(root, "", res);
        return res;
    }
    
    private void searchBT(TreeNode root, String path, List<String> res) {
        if (root.left == null && root.right == null) {
            res.add(path + root.val);
            return;
        }
        if (root.left != null) {
            searchBT(root.left, path + root.val + "->", res);
        }
        if (root.right != null) {
            searchBT(root.right, path + root.val + "->", res);
        }
    }
    
}
