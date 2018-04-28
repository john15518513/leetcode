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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int numSize = que.size();
            vector<int> tmp;
            for (int i = 0; i < numSize; i++) {
                auto target = que.front();
                que.pop();
                if (target->left) que.push(target->left);
                if (target->right) que.push(target->right);
                tmp.push_back(target->val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
