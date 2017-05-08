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
    TreeNode* convertBST(TreeNode* root) {
        int c = 0;
        dfs(root, c);
        return root;
    }
    void dfs(TreeNode* root, int &sum) {
        if (!root) return;
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val; 
        dfs(root->left, sum);
        
    }
};
