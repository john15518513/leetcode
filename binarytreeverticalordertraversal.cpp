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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> vt;
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<int, TreeNode*>> que;
        que.push(make_pair(0, root));
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                auto target = que.front();
                que.pop();
                vt[target.first].push_back(target.second->val);
                if (target.second->left) que.push(make_pair(target.first-1, target.second->left));
                if (target.second->right) que.push(make_pair(target.first+1, target.second->right));
            }
            
        }
        for (auto it = vt.begin(); it != vt.end(); it++) res.push_back(it->second);
        return res;
    }
};
