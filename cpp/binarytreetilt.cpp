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
    Solution(): res(0) {}
    int findTilt(TreeNode* root) {
        helper(root);
        return res;
    }
    
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        res += abs(left-right);
        //cout << root->val+left+right << endl;
        return root->val+left+right;
    }
private:
    int res;
};
