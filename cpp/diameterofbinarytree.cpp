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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        //cout << depth(root->left) << " " << depth(root->right)<<endl; 
        return max(depth(root->left)+depth(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
};
