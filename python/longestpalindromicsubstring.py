class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        self.lo = 0
        self.maxLen = 0
        if len(s) < 2:
            return s
        for i in xrange(len(s)):
            self.maxPalindrome(i,i,s)
            self.maxPalindrome(i, i+1, s)
            
        return s[self.lo: self.lo+self.maxLen]
        
    def maxPalindrome(self, i, j, s):
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
        if self.maxLen < j-i-1:
            self.lo = i+1
            self.maxLen = j-i-1
