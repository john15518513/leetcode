class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if not n%2:
            return True
        dp = [[-1 for _ in xrange(n)] for _ in xrange(n)]
        maxSum = self.dfs(dp, 0, n-1, nums)
        return 2*maxSum >= sum(nums)
        
    def dfs(self, dp, i, j, nums):
        """
        :dp: dp table
        :i: left index
        :j: right index
        """
        if i > j:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        a = nums[i] + min(self.dfs(dp, i+1, j-1, nums), self.dfs(dp, i+2, j, nums))
        b = nums[j] + min(self.dfs(dp, i+1, j-1, nums), self.dfs(dp, i, j-2, nums))
        dp[i][j] = max(a,b)
        
        return dp[i][j]
