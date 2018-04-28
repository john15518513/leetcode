class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        stack = []
        n = len(nums)
        res = [-1 for _ in xrange(n)]
        for i in xrange(2*n):
            num = nums[i%n]
            while len(stack)!=0 and nums[stack[-1]] < num:
                res[stack.pop()] = num
            if i < n:
                stack.append(i)
                
        return res
