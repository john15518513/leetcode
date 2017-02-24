class Solution(object):
    
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        def ga(word, pos, cur, cnt):
        
            if pos == len(word):
                if cnt > 0:
                    cur += str(cnt)
                res.append(cur)
            else:
                ga(word, pos+1, cur, cnt+1)
                ga(word, pos+1, cur + (str(cnt) if cnt>0 else '') + word[pos] , 0)
        res = []
        ga(word, 0, "", 0)
        return res
        
    
