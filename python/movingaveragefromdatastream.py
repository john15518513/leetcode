class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.size = size
        self.q = []
        

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        m = len(self.q)
        if m < self.size:
            self.q.append(val)
            return sum(self.q)/float(m+1)
        else:
            self.q.append(val)
            self.q.pop(0)
            return sum(self.q)/float(m)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
