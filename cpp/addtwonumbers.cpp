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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0);
        ListNode *tmp = root;
        int c = 0;
        while (l1 or l2 or c) {
            int v1 = 0, v2 = 0;
            if (l1) {
                v1 = l1->val;
                l1 = l1 -> next;
            }
            if (l2) {
                v2 = l2->val;
                l2 = l2 -> next; 
            }
            int sum = (v1 + v2 + c)%10;
            c = (v1 + v2 + c)/10;
            tmp -> next = new ListNode(sum);
            tmp = tmp -> next;
        }
        return root->next;
    }
};
