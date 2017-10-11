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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* lastNode = NULL;
        while (root or !s.empty()) {
            if (root) {
                s.push(root);
                root = root -> left;
            }
            else {
                TreeNode* topNode = s.top();
                if (topNode -> right && lastNode != topNode -> right)
                    root = topNode -> right;
                else {
                    res.push_back(topNode -> val);
                    lastNode = topNode;
                    s.pop();
                }
            }
        }
        return res;  
    }
};
