class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        h = []
        for row in matrix:
            for cell in row:
                if len(h) == k:
                    if h[0]*-1 < cell:
                        break
                    heapq.heappushpop(h, -1*cell)
                else:
                    heapq.heappush(h, -1*cell)
                
        return heapq.heappop(h)*-1
