class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x in (0,1):
            return x
        pre, post = 1, x
        while True:
            if ((pre+post)//2)**2 <= x and ((pre+post)//2+1)**2 > x:
                return (pre+post)//2
            elif ((pre+post)//2)**2 > x:
                post = (pre+post)//2
                #last = post
            elif ((pre+post)//2)**2 < x:
                pre = (pre+post)//2
                #last = pre
            
