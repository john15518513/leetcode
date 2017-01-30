class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        for i in xrange(1,10):
            self.dfs(i, n, res)
        return res
    def dfs(self, cur ,n, res):
        if cur > n:
            return
        res.append(cur)
        for i in xrange(10):
            if cur*10+i > n:
                return
            self.dfs(cur*10+i, n, res)
