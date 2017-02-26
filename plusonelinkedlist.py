# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def plusOne(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head.val == 0:
            head.val = 1
            return head
        c = self.dfs(head)
        if c == 0:
            return head
        else:
            newHead = ListNode(1)
            newHead.next = head
            return newHead
    def dfs(self, head):
        if not head.next:
            c = (head.val+1)/10
            head.val = (head.val+1)%10
            return c
        c = self.dfs(head.next)
        tmp = head.val
        head.val = (head.val+c)%10
        c = (tmp+c)/10
        return c
