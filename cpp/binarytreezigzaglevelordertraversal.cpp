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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        int index = 0;
        while (!que.empty()) {
            int num = que.size();
            vector<int> tmp;
            for (int i = 0; i < num; i++) {
                auto target = que.front();
                que.pop();
                if (target->left) que.push(target->left);
                if (target->right) que.push(target->right);
                tmp.push_back(target->val);
            }
            if (index%2) reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            index++;
        }
        return res;
    }
};
