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
    int findSecondMinimumValue(TreeNode* root) {
        int first = INT_MAX;
        int second = INT_MAX;
        dfs(root, first, second);
        if (first == INT_MAX or second == INT_MAX) return -1;
        return second;
        
    }
    void dfs(TreeNode* root, int &first, int &second) {
        if (!root) return;
        if (root->val < first) first = root->val;
        else if (root->val > first and root->val < second) second = root->val;
        dfs(root->left, first, second);
        dfs(root->right, first, second);
    }
};
