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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*if (!head) return NULL;
        ListNode* root;
        auto tmp = reverse(head, k);
        root = tmp[0];
        ListNode* tail = tmp[1];
        ListNode* next = tmp[2];
        //cout << root->val << " " << tail->val << " " << next->val;
        while (next) {
            tmp = reverse(next, k);
            tail->next = tmp[0];
            tail = tmp[1];
            next = tmp[2];
        }
        return root;*/
        int count = k;
        auto cur = head;
        while (cur and count > 0) {
            cur = cur->next;
            count--;
        }
        if (count == 0) {
            cur = reverseKGroup(cur, k);
            while (k > 0) {
                auto tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
                k--;
            }
            head = cur;
        }
        return head;    
    }
    /*vector<ListNode*> reverse(ListNode* head, int k) {
        ListNode* pre = NULL;
        ListNode* tmp = NULL;
        ListNode* tail = head;
        while (k > 0 and head) {
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
            k--;
        }
        return vector<ListNode*> {pre, tail, head};
    }*/
};
