class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        res = [0 for _ in xrange(rowIndex+1)]
        res[0] = 1
        for i in xrange(1,rowIndex+1):
            for j in xrange(i,0,-1):
                res[j] += res[j-1]
        return res
