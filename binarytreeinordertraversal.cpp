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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        stack<TreeNode*> stack;
        vector<int> res;
        while (root or !stack.empty()) {
            if (root) {
                stack.push(root);
                root = root->left;
            }
            else {
                auto target = stack.top();
                stack.pop();
                res.push_back(target->val);
                root = target->right;
            }
        }
        return res;
    }
};
