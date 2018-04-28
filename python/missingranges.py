class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        res = []
        if not nums:
            return [str(lower)] if lower == upper else [str(lower)+"->"+str(upper)]
        if lower < nums[0]:
            nums.insert(0, lower-1)
        if upper > nums[-1]:
            nums.append(upper+1)
        #print nums
        for i in xrange(1,len(nums)):
            if nums[i]-nums[i-1] == 2:
                res.append(str(nums[i]-1))
            elif nums[i]-nums[i-1] > 2:
                res.append(str(nums[i-1]+1)+"->"+str(nums[i]-1))
        return res
