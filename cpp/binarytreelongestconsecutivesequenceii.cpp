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
        dfs(root);
        return maxV;
    }
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return make_pair(0, 0);
        int inc = 1, dec = 1;
        if (root->left) {
            auto p = dfs(root->left);
            if (root->left->val + 1 == root->val) {
                dec = p.second + 1;
            }
            else if(root->left->val - 1 == root->val) {
                inc = p.first + 1;
            }
        }
        if (root->right) {
            auto p = dfs(root->right);
            if (root->right->val == root->val + 1) {
                inc = max(inc, p.first + 1);
            }
            else if(root->right->val == root->val - 1) {
                dec = max(dec, p.second + 1);
            }
        }
        maxV = max(maxV, inc+dec-1);
        return make_pair(inc, dec);
    }
    int maxV = 0;
};
