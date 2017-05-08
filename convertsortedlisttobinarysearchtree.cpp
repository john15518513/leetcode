/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return find(head, NULL);
    }
    
    TreeNode* find(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == tail) return NULL;
        while (fast!=tail and fast->next!=tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = find(head, slow);
        root->right = find(slow->next, tail);
        return root;
    }
};
