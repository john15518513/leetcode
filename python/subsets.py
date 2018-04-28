class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.res = []
        self.dfs(nums,0, [])
        return self.res
        
    def dfs(self, nums, i, tmp):
        if i == len(nums):
            self.res.append(tmp[:])
            return
        tmp.append(nums[i])
        self.dfs(nums, i+1, tmp)
        tmp.pop()
        self.dfs(nums, i+1, tmp)
        
