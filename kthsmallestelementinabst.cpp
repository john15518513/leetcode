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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
    void dfs(TreeNode* root, int &k) {
        if (!root) return;
        dfs(root->left, k);
        k -= 1;
        if (k == 0) {
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }
private:
    int res;
};
