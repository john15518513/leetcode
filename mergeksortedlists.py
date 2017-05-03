# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        k = len(lists)
        minHeap = []
        root = ptr = ListNode(0)
        for i in xrange(k):
            if lists[i] != None:
                heapq.heappush(minHeap, (lists[i].val, i))
        while minHeap:
            v, i = heapq.heappop(minHeap)
            ptr.next = ListNode(v)
            lists[i] = lists[i].next
            if lists[i] != None:
                heapq.heappush(minHeap, (lists[i].val, i))
            ptr = ptr.next
        return root.next
        
