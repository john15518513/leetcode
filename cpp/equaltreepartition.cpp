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
    bool checkEqualTree(TreeNode* root) {
        if (!root or (!root->left and !root->right)) return false;
        int dummy = dfs(root);
        if (dummy == 0) return pool[dummy] > 1;
        if (dummy%2 == 0 and pool.find(dummy/2) != pool.end()) return true;
        return false;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        pool[left+right+root->val]++;
        return left+right+root->val;
    }
private:
    unordered_map<int, int> pool;
};
