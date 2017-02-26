class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [[0, 0] for _ in xrange(n+1)]
        for i in xrange(1,n+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            dp[i][1] = dp[i-1][0] + nums[i-1]
        
        return max(dp[-1][0], dp[-1][1])
        
        
