class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
         
        vowels = set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        index = []
        for i in range(len(s)):
            if  s[i] in vowels:
                index.append(s[i])
        s = list(s)        
        for i in range(len(s)):
            if s[i] in vowels:
                s[i] = index.pop()
        s = "".join(s)
        return s
