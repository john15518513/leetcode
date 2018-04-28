class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        sumN = 0 
        dic = {}
        dic[0] = -1
        for i in xrange(len(nums)):
            sumN += nums[i]
            if k!=0:
                sumN %= k 
            if sumN in dic:
                if i-dic[sumN]>1:
                    return True
            else:
                dic[sumN] = i
        return False
