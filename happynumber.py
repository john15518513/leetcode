class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def squareSum(i):
            sumN = 0
            while i:
                tmp = i%10
                sumN += tmp**2
                i /= 10
            return sumN
            
        slow = fast = n
        slow = squareSum(slow)
        fast = squareSum(fast)
        fast = squareSum(fast)
        while slow!=fast:
            slow = squareSum(slow)
            fast = squareSum(fast)
            fast = squareSum(fast)
        
        return True if slow==1 else False
        
