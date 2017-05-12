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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (sameTree(s, t)) return true;
        return isSubtree(s->left, t) or isSubtree(s->right, t);
    }
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s or !t) {
            return s == t;
        }
        if (s->val != t->val) return false;
        return sameTree(s->left, t->left) and sameTree(s->right, t->right);
    }
};
