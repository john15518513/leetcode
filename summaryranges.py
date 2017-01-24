class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []
        start, end = 0, 0
        if not nums:
            return res
        while end < len(nums):
            
            while end+1 < len(nums) and nums[end+1] == nums[end]+1:
                end += 1
            #print start, end
            if start != end:
                res.append(str(nums[start])+"->"+str(nums[end]))
            else:
                res.append(str(nums[start]))
            start = end = end+1
            
        return res
