class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxV = 0
        counter = 0
        for i in nums:
            if i == 0:
                counter = 0
            else:
                counter += 1
                maxV = max(maxV, counter)
                
        return maxV
        
        
