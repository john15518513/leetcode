class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        self.res = []
        self.fringe = set()
        self.dfs(nums, [], 0)
        return self.res
        
    def dfs(self, nums, res, index):
        if len(res) >= 2:
            if tuple(res) not in self.fringe:
                self.res.append(res[:])
                self.fringe.add(tuple(res))
        for i in xrange(index, len(nums)):
            if not res or nums[i] >= res[-1]:
                res.append(nums[i])
                self.dfs(nums, res, i+1)
                res.pop()
