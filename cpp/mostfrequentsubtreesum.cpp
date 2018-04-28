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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int dummy = dfs(root);
        vector<int> res;
        for (auto &e: count) {
            if (e.second == mostFreq) res.push_back(e.first);
        }
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = root->val + left + right;
        count[sum]++;
        mostFreq = max(mostFreq, count[sum]);
        return sum;
    }
private:
    unordered_map<int, int> count;
    int mostFreq = 0;
};
