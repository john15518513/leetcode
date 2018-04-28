# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        
        self.d = {}
        if not head:
            return None
        root = RandomListNode(head.label)
        self.d[head] = root
        root.next = self.dfs(head.next)
        root.random = self.dfs(head.random)
        return root
        
    def dfs(self, head):
        if not head:
            return None
        #print head.label
        m = self.d.get(head)
        if m:
            return m
        else:
            tmp = RandomListNode(head.label)
            self.d[head] = tmp
            tmp.next = self.dfs(head.next)
            tmp.random = self.dfs(head.random)
        
        return tmp
