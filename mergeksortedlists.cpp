/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    struct cmp {
      bool operator()(const ListNode* l, const ListNode* r){
          return l->val > r->val;
      }  
    };
    /*
    static bool cmp(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }*/
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*ListNode* root = new ListNode(0);
        ListNode* tail = root;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto l: lists)
            if (l) pq.push(l);
        
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
            
        }
        return root->next;
        */
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        vector<ListNode*> mh;
        for (auto l: lists) {
            if(l) mh.push_back(l);
        }
        
        make_heap(mh.begin(), mh.end(), cmp());
        
        while (!mh.empty()) {
            tail->next = mh.front();
            pop_heap(mh.begin(), mh.end(), cmp()); 
            mh.pop_back();
            tail = tail->next;
            if (tail->next) {
                mh.push_back(tail->next);
                push_heap(mh.begin(), mh.end(), cmp());
            }
        }
        return root->next;
        
    }
};
