class Solution(object):
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        dic = {"++": "--", "--": "++", "+-": "-+", "-+": "+-"}
        for i in xrange(len(s)-1):
            if s[i:i+2] == "++":
                res.append(s[:i] + dic[s[i:i+2]] + s[i+2:])
        return res
            
