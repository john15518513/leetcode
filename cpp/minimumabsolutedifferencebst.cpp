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
    int getMinimumDifference(TreeNode* root) {
        minV = INT_MAX;
        TreeNode* pre = NULL;
        inorder(root, pre);
        return minV;
    }
    void inorder(TreeNode* root, TreeNode* &pre) {
        if (!root) return;
        inorder(root->left, pre);
        if (pre) {
            minV = min(minV, abs(root->val - pre->val));
        }
        pre = root;
        inorder(root->right, pre);
    }
    int minV;
};
