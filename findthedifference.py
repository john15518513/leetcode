class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        s = list(s)
        t = list(t)
        for w in t:
            if w in s:
                s.remove(w)
            else:
                return w
