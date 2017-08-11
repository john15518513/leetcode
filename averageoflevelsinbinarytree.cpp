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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> res;
        que.push(root);
        while (!que.empty()) {
            int num = que.size();
            double sum = 0;
            for (int i = 0; i < num; i++) {
                //cout << que.front()->val << endl;
                sum += que.front()->val/double(num);
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                que.pop();
            }
            //cout << "sum:" <<sum << endl;
            res.push_back(sum);
        }
        return res;
    }
};
