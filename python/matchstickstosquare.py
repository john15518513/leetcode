class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        total_length = sum(nums)
        length = sum(nums) / 4 
        
        if len(nums) < 4 or total_length % 4 != 0 or max(nums)>length: return False
        nums = sorted(nums, reverse=True)
        res = self.dfs(nums, [0,0,0,0], 0, length)
        return res
        
    def dfs(self, nums, sides, index, length):
        if len(nums) == index:
            return all(side == length for side in sides)
            
        for i, side in enumerate(sides):
            if side + nums[index] > length: continue
            sides[i] += nums[index]
            if self.dfs(nums, sides, index+1, length): return True
            sides[i] -= nums[index]
        
        return False
        
        
