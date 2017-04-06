class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        dic = {}
        for i in s:
            dic[i] = dic.get(i,0)+1
        pair = []
        for key in dic:
            pair.append((key, dic[key]))
        pair.sort(key=lambda x: x[1])
        res = ""
        while pair:
            s, n = pair.pop()
            res += s*n
        return res
        
        
