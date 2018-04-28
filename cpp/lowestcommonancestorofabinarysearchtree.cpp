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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        //if (p->val > q->val) swap(p, q);
        while (true) {
            if (cur->val < p->val and cur->val < q->val) cur = cur->right;
            else if (cur->val > p->val and cur->val > q->val) cur = cur->left;
            else return cur;
        }   
        
    }
};
