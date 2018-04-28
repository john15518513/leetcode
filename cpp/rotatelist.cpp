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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* ptr = head;
        int len = 1;
        while (ptr->next) {
            ptr = ptr->next;
            len++;
        }
        ptr->next = head;
        k %= len;
        k = len-k;
        for(auto i=0; i<k; i++) ptr = ptr->next;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};
