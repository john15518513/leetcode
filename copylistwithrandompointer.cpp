/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> hash;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return head;
        RandomListNode *newHead = new RandomListNode(head->label);
        hash[head] = newHead;
        newHead -> next = dfs(head->next);
        newHead -> random = dfs(head->random);
        return newHead;
    }
    
    RandomListNode *dfs(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        if (hash.find(head) != hash.end())
            return hash[head];
        RandomListNode *newHead = new RandomListNode(head->label);
        hash[head] = newHead;
        newHead -> next = dfs(head->next);
        newHead -> random = dfs(head->random);
        
        return newHead;
    }
};
