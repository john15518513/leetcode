class Solution(object):
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        dic = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}
        original = list(str(num))
        rotate = []
        for s in original:
            if s in dic:
                rotate.append(dic[s])
            else:
                return False
        return rotate[::-1] == original
