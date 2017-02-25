class Solution(object):
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return self.sn(n, n)
        
    def sn(self, cnt, n):
        
        if cnt == 0:
            return [""]
        if cnt == 1:
            return ["0", "1", "8"]
            
        l = self.sn(cnt-2, n)
        res = []
        for s in l:
            if n!=cnt:
                res.append("0"+s+"0")
            res.append("1"+s+"1")
            res.append("6"+s+"9")
            res.append("8"+s+"8")
            res.append("9"+s+"6")
        return res
        
        
