class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.res = []
        self.index = 0
        i = 0
        while i < len(v1) or i < len(v2):
            if i < len(v1):
                self.res.append(v1[i])
            if i < len(v2):
                self.res.append(v2[i])
            i += 1
        self.len = len(self.res)

    def next(self):
        """
        :rtype: int
        """
        return self.res[self.index-1]
        

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.index < self.len:
            self.index += 1
            return True
        return False
        

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
