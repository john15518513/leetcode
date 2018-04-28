class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        pre = strs[0]
        for i in xrange(1, len(strs)):
            j = 0
            while (j<min(len(strs[i]), len(pre)) and pre[j] == strs[i][j]):
                #print pre[j], strs[i][j]
                j += 1
            
            pre = pre[:j]
        return pre
                
