class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        nums = [-1 for _ in xrange(n)]
        def find(i):
            if nums[i] == -1:
                return i
            return find(nums[i])
        for i in xrange(len(edges)):
            x = find(edges[i][0])
            y = find(edges[i][1])
            
            if x == y:
                return False
            nums[x] = y
            
        return len(edges) == n-1
