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
    bool hasCycle(ListNode *head) {
        if (!head or !head->next) return false;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (slow != fast) {
            slow = slow->next;
            if (fast and fast->next){
                fast = fast->next->next;
            }
            else return false;
        }
        return true;
    }
};
