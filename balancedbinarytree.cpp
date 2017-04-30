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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(depth(root->left)-depth(root->right)) <= 1 and isBalanced(root->left) and isBalanced(root->right);
    }
    int depth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(depth(root->left), depth(root->right));
    }
};
