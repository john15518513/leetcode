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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = dfs(preorder, inorder, 0, inorder.size()-1);
        return root;
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int i, int j) {
        if (i > j) return NULL;
        int val = preorder[0];
        preorder.erase(preorder.begin());
        TreeNode *root = new TreeNode(val);
        int index = find(inorder, val);
        root->left = dfs(preorder, inorder, i, index-1); 
        root->right = dfs(preorder, inorder, index+1, j);
        return root;
    }
    int find(vector<int>& inorder, int target) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == target) return i;
        }
    }
    
};
