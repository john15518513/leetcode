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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trim(root, L, R);
    }
    TreeNode* trim(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        if (root->val < L) return trim(root->right, L, R);
        if (root->val > R) return trim(root->left, L, R);
        root->left = trim(root->left, L, R);
        root->right = trim(root->right, L, R);
        return root;
    }
};
