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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        string path = "";
        dfs(root, path, res);
        return res;
    }
    void dfs(TreeNode* root, string& path, int& res) {
        if (!root) return;
        path.push_back(root->val + '0');
        if (!root->left and !root->right) 
            res += stoi(path);
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        path.pop_back();
    }
};
