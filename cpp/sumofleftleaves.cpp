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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, int& res) {
        if (!root) return;
        if (root->left and !root->left->left and !root->left->right) {
            //cout << root->val << endl;
            res += root->left->val;
        }
        dfs(root->left, res);
        dfs(root->right, res);   
    }
};
