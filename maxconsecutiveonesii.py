class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, h = 0, 0
        maxValue = 0
        k = 1
        while h < len(nums):
            if nums[h] == 0:
                k -= 1
            while k < 0:
                if nums[l] == 0:
                    k += 1
                l += 1
            maxValue = max(maxValue, h-l+1)
            h += 1
            
        return maxValue
