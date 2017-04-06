class Solution(object):
    def findContestMatch(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = map(str, range(1, n+1))
        while n > 1:
            res = [ "("+res[i]+","+res[n-1-i]+")" for i in xrange(n>>1)]
            n >>= 1
        return "".join(res)
