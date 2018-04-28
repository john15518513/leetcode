/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int c = dfs(head);
        if (c) {
            ListNode* root = new ListNode(c);
            root->next = head;
            return root;
        } 
        return head;
    }
    int dfs(ListNode* head) {
        if (!head) return 1;
        int c = dfs(head->next);
        int val = (head->val + c)%10;
        c = (head->val + c)/10;
        head->val = val;
        return c;
    }
};
