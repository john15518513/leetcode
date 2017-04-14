class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        self.res = []
        self.dfs(s, 0, [])
        return self.res
        
    def dfs(self, s, begin, tmp):
        if begin == len(s):
            self.res.append(tmp[:])
        i = begin
        while i < len(s):
            if self.isPalindrome(s, begin, i):
                tmp.append(s[begin:i+1])
                self.dfs(s, i+1, tmp)
                tmp.pop()
            i += 1
            
    def isPalindrome(self, s, i, j):
        if i == j:
            return True
        while i<j:
            if s[i]!=s[j]:
                return False
            i += 1
            j -= 1
        return True
