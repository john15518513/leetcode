class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        c = 1
        for i in xrange(len(digits)-1, -1, -1):
            digits[i] += c
            if digits[i] >= 10:
                
                digits[i] -= 10
                c = 1
            else:
                c = 0
        
        if c != 0:
            digits.insert(0,1)
        return digits
        
