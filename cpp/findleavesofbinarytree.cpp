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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        //cout << root->val << endl;
        dfs(root, res);
        //if (!root) cout << "c" << endl;
        //else cout << root->val << endl;
        return res;
    }
    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return 0;
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if (level-1 == res.size()) res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        *root = NULL;
        return level;
    }
};
