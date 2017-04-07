class Solution(object):
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        if n == 0 or k == 0:
            return 0
        if n == 1: return k
        same = [ k for _ in xrange(n)]
        diff = [ k for _ in xrange(n)]
        diff[1] = k*(k-1)
        for i in xrange(2, n):
            same[i] = diff[i-1]
            diff[i] = same[i-1]*(k-1) + diff[i-1]*(k-1)
            
        return diff[-1] + same[-1]
