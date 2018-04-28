class Solution(object):
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        n = len(costs)
        dp = [[0,0,0] for i in xrange(n+1)]
        for i in xrange(1, n+1):
            dp[i][0] = min(dp[i-1][1], dp[i-1][2])+costs[i-1][0]
            dp[i][1] = min(dp[i-1][0], dp[i-1][2])+costs[i-1][1]
            dp[i][2] = min(dp[i-1][1], dp[i-1][0])+costs[i-1][2]
        return min(dp[-1])
