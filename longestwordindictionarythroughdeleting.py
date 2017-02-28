class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        d.sort()
        d.sort(key = lambda s: len(s), reverse = True)
        #print d
        for i in d:
            c = 1
            index = 0
            for w in i:
                move = s[index:].find(w)
                if move == -1:
                    c = 0
                    break
                index = move + 1 + index
                
                    
            if c:
                return i
        
        return ""
