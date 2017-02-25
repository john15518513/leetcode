class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res = []
        for i in findNums:
            index = nums.index(i)
            res.append(-1)
            for j in xrange(index+1, n):
                if nums[j] > i:
                    res[-1] = nums[j]
                    break
        return res
