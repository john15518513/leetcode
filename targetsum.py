class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        if (sum(nums)+S)&1 or sum(nums) < S:
            return 0
        target = (sum(nums)+S)/2
        n = len(nums)
        dp = [0 for _ in xrange(target+1)]
        
        dp[0] = 1
            
        for num in nums:
            for j in xrange(target, num-1, -1):
                    dp[j] += dp[j-num]
            #print num
        
        return dp[-1]
        
        
