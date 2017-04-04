class Solution(object):
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sumN = 0
        maxN = 0
        dic = {}
        for i in xrange(len(nums)):
            sumN += nums[i]
            if sumN == k:
                maxN = i + 1
            elif sumN-k in dic:
                maxN = max(maxN, i-dic[sumN-k])
            if sumN not in dic:
                dic[sumN] = i
        return maxN
