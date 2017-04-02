class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        h = []
        for i in nums1:
            for j in nums2:
                if len(h) == k:
                    if h[0]*-1 < (i+j):
                        break
                    heapq.heappushpop(h, (-1*(i+j),[i,j]))
                else:
                    heapq.heappush(h, (-1*(i+j),[i,j]))
        res = []
        while len(h):
            res.append(heapq.heappop(h)[1])
        return res[::-1]
