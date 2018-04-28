class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        l = len(citations)
        bucket = [0 for _ in xrange(l+1)]
        for citeNum in citations:
            if citeNum < l:
                bucket[citeNum] += 1
            else:
                bucket[-1] += 1
        t = 0
        res = 0
        for i in xrange(l,-1,-1):
            t += bucket[i]
            if t>=i:
                return i
        return 0
        
