/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root->left, root, 1), dfs(root->right, root, 1));
    }
    int dfs(TreeNode* root, TreeNode* pre, int depth) {
        if (!root) return depth;
        if (pre->val+1 == root->val) depth += 1;
        else depth = 1;
        pre = root;
        return max(depth, max(dfs(root->left, pre, depth), dfs(root->right, pre, depth)));
    }

};
