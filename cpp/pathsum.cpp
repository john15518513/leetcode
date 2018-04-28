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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }
    bool dfs(TreeNode* root, int sum, int path) {
        if (!root) return false;
        if (!root->left and !root->right and path+root->val == sum) return true;
        path += root->val;
        return dfs(root->left, sum, path) or dfs(root->right, sum, path);
    }
};
