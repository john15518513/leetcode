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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        dfs(root, tmp, sum);
        return res;
    }
    void dfs(TreeNode* root, vector<int> &tmp, int sum) {
        if (!root) return;
        sum -= root->val;
        tmp.push_back(root->val);
        if (sum == 0 and !root->left and !root->right) {
            res.push_back(tmp);
        }
        dfs(root->left, tmp, sum);
        dfs(root->right, tmp, sum);
        tmp.pop_back();
    }
private:
    vector<vector<int>> res;
};
