class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(0, nums, res)
        return res
        
    def dfs(self, i, nums, res):
        if i >= len(nums):
            res.append(nums[:])
            return
        for j in xrange(i, len(nums)):
            nums[i], nums[j] = nums[j], nums[i]
            self.dfs(i+1, nums, res)
            nums[i], nums[j] = nums[j], nums[i]
