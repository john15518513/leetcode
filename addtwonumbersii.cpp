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
        stack <ListNode*> l1Stack;
        stack <ListNode*> l2Stack;
        ListNode *tmpPtr = l1;
        while (tmpPtr != NULL) {
            l1Stack.push(tmpPtr);
            tmpPtr = tmpPtr -> next;
        }
        tmpPtr = l2;
        while (tmpPtr != NULL){
            l2Stack.push(tmpPtr);
            tmpPtr = tmpPtr -> next;
        }
        int c = 0;
        int val1 = 0;
        int val2 = 0;
        ListNode *head = NULL;
        while (!l1Stack.empty() or !l2Stack.empty()){
            if (!l1Stack.empty()){
                val1 = l1Stack.top()->val;
                l1Stack.pop();
            }
            if (!l2Stack.empty()){
                val2 = l2Stack.top()->val;
                l2Stack.pop();
            }
            //cout << val1 << " " << val2 << endl;
            int value = (c+val1+val2)%10;
            c = (c+val1+val2)/10;
            head = createNode(value, head);
            val1 = 0;
            val2 = 0;
        }
        if (c==1){
            head = createNode(1, head);
        }
        
        return head;
    }
    
    ListNode* createNode(int value, ListNode *head){
        ListNode *newNode = new ListNode(value);
        newNode -> next = head;
        return newNode;
    }
};
