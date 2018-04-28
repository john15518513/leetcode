class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1:
            return 0
        K = 2
        maxProf = 0
        f = [[0 for _ in xrange(len(prices))] for _ in xrange(K+1)]
        for i in xrange(1, K+1):
            tmpMax = f[i-1][0] - prices[0]
            for j in xrange(1, len(prices)):
                f[i][j] = max(f[i][j-1], prices[j]+tmpMax)
                tmpMax = max(tmpMax, f[i-1][j] - prices[j])
                maxProf = max(f[i][j], maxProf)
        print f
        return maxProf
