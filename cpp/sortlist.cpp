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
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        while (fast and fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        auto head1 = sortList(head);
        auto head2 = sortList(slow);
        
        return merge(head1, head2);
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* root = new ListNode(0);
        auto cur = root;
        while (head1 and head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            }
            else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        while (head1) {
            cur->next = head1;
            head1 = head1->next;
            cur = cur->next;
        }
        while (head2) {
            cur->next = head2;
            head2 = head2->next;
            cur = cur->next;
        }
        return root->next;
    }
};
