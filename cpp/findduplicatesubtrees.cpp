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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
    string dfs(TreeNode* root) {
        if (!root) return "#";
        string tmp =   "(" + dfs(root->left) + to_string(root->val) + dfs(root->right) + ")";
        if (hash[tmp] == 1) res.push_back(root);
        hash[tmp]++;
        return tmp;
    }
private:
    vector<TreeNode*> res;
    unordered_map<string, int> hash;
};
