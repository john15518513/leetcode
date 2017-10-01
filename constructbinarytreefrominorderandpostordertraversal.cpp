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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, inorder.size()-1);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int low, int high) {
        if (low > high) return NULL;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        int j = find(inorder, root->val);
        root->right = dfs(inorder, postorder, j+1, high);
        root->left = dfs(inorder, postorder, low, j-1);
        return root;
    }
    int find(vector<int>& inorder, int t) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == t) return i;
        }
    }
};
