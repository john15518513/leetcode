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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* slow = root;
        ListNode* fast = root;
        for (int i = 0; i < n+1; i++) fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return root->next;
        
    }
};
