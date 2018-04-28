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
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        auto v1 = head;
        auto v2 = head->next;
        auto root = v2;
        auto pre = new ListNode(0);
        while (v2) {
            auto tmp = v2->next;
            v2->next = v1;
            v1->next = tmp;
            pre->next = v2;
            pre = v1;
            v1 = tmp;
            v2 = tmp? tmp->next:NULL;
        }
        return root;
    }
};
