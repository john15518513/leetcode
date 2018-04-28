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
    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        dfs(root);
        return maxSum;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        maxSum = max(maxSum, root->val+(left<0?0:left)+(right<0?0:right));
        return left<0 and right<0? root->val : root->val + max(left, right);
    }
    int maxSum;
};
