# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        cur = head
        root = head.next
        pre = self
        while cur and cur.next:
            tmp = cur.next.next
            cur.next.next = cur
            pre.next = cur.next
            cur.next = tmp
            pre = cur
            cur = tmp
        
        return root
            
