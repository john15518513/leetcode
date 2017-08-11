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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> pool;
        return dfs(root, k, pool);
    }
    bool dfs(TreeNode* root, int target, unordered_set<int> &pool) {
        if (!root) return false;
        if (pool.find(root->val) != pool.end()) return true;
        pool.insert(target-root->val);
        return dfs(root->left, target, pool) or dfs(root->right, target, pool);
    }
};
