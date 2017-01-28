class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        curmax = maxsum = nums[0]
        for i in nums[1:]:
            curmax = max(i, curmax+i)
            maxsum = max(maxsum, curmax)
        return maxsum
