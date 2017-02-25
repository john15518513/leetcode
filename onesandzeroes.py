class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0 for _ in xrange(n+1)] for _ in xrange(m+1)]
        for s in strs:
            numZeroes = 0
            numOnes = 0
            for w in s:
                if w == '0':
                    numZeroes += 1
                else:
                    numOnes += 1
                    
            for i in range(m, numZeroes-1, -1):
                for j in range(n, numOnes-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-numZeroes][j-numOnes]+1)
        return dp[m][n]
