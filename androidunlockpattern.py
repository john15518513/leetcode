class Solution(object):
    def numberOfPatterns(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        res = 0
        vis = [False for i in xrange(10)]
        skip = [[0 for i in xrange(10)] for j in xrange(10)]
        skip[1][3] = skip[3][1] = 2
        skip[1][7] = skip[7][1] = 4
        skip[3][9] = skip[9][3] = 6
        skip[7][9] = skip[9][7] = 8
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5
        for i in xrange(m,n+1):
            res += self.DFS(vis, skip, 1, i-1)*4
            res += self.DFS(vis, skip, 2, i-1)*4
            res += self.DFS(vis, skip, 5, i-1)
        
        return res
        
    def DFS(self, vis, skip, cur, re):
        if re == 0:
            return 1
        vis[cur] = True
        res = 0
        for i in xrange(1,10):
            if not vis[i] and (skip[cur][i]==0 or vis[skip[cur][i]]):
                res += self.DFS(vis, skip, i, re - 1)
        vis[cur] = False
        
        return res
        
        
        
