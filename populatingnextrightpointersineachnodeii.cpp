/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0);
        TreeLinkNode *ptr = dummy;
        while (root) {
           ptr->next = root->left;
           if (ptr->next) {
               ptr = ptr->next;
           } 
           ptr->next = root->right;
           if (ptr->next) {
               ptr = ptr->next;
           }
           root = root->next;
           if (!root) {
                ptr = dummy;
                root = dummy->next;
           }
        }
    }
};
