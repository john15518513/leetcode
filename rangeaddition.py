class Solution(object):
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        res = [0 for _ in xrange(length)]
        for i in updates:
            start = i[0]
            end = i[1]
            val = i[2]
            res[start] += val
            if end < length-1:
                res[end+1] -= val
        sum = 0
        for i in xrange(length):
            sum += res[i]
            res[i] = sum
        return res
