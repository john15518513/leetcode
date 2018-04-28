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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return maxV-1;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = 1;
        if (root->left and root->left->val == root->val) sum += l;
        else l = 0;
        if (root->right and root->right->val == root->val) sum += r;
        else r = 0;
        maxV = max(maxV, sum);
        return max(sum-l, sum-r);
    }
    int maxV = 0;
};
