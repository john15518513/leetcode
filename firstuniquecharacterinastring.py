class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not len(s):
            return -1
        elif len(s) == 1:
            return 0
        elif s[0] not in s[1:]:
            return 0
        
        for i in range(1,len(s)-1):
            #print s[i], s[:i], s[i+1:]
            if s[i] not in s[:i] and s[i] not in s[i+1:]:
                return i
        if s[-1] not in s[:-1]:
            return len(s)-1
        return -1
