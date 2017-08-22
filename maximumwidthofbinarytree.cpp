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
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root, 0, 0, vector<pair<int, int>>() = {});
    }
    int dfs(TreeNode* root, int level, int order, vector<pair<int, int>>& vec) {
        if(root == NULL)return 0;
        if(vec.size() == level) vec.push_back({order, order});
        else vec[level].second = order;
        return max({vec[level].second - vec[level].first+1, dfs(root->left, level + 1, 2*order, vec), dfs(root->right, level + 1, 2*order + 1, vec)});
    }

};
