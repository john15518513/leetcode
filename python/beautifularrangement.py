class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        numList = [i for i in xrange(1,N+1)]
        return self.permutation(N, numList)
        
    def permutation(self, n, vs):
            if n == 1:
                return 1
            ans = 0
            for i in xrange(n):
                if vs[i]%n==0 or n%vs[i]==0: 
                    vs[i], vs[n-1] = vs[n-1], vs[i]
                    ans += self.permutation(n-1, vs)
                    vs[i], vs[n-1] = vs[n-1], vs[i]
            return ans
            
