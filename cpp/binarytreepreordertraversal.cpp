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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int> {};
        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);
        while (!s.empty()) {
            auto target = s.top();
            s.pop();
            res.push_back(target->val);
            if (target->right) s.push(target->right);
            if (target->left) s.push(target->left);
        }
        return res;
    }
};
