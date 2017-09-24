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
    void reorderList(ListNode* head) {
        if (!head or !head->next) return;
        auto slow = head;
        auto fast = head;
        ListNode* pre = NULL;
        while (fast and fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        fast = reverse(slow);
        auto cur = head;
        slow = head;
        while (slow and fast) {
            auto tmp1 = slow->next;
            auto tmp2 = fast->next;
            cur->next = slow;
            cur = cur->next;
            cur->next = fast;
            cur = cur->next;
            slow = tmp1;
            fast = tmp2;
        }
        if (fast) cur->next = fast;
        
    }
    ListNode* reverse(ListNode* root) {
        ListNode* pre = NULL;
        while (root) {
            auto tmp = root->next;
            root->next = pre;
            pre = root;
            root = tmp;
        }
        return pre;
    }

};
