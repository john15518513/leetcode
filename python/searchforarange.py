class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = [-1, -1]
        i, j = 0, len(nums)-1
        while i<j:
            mid = (i+j)/2
            if nums[mid] < target:
                i = mid + 1
            else:
                j = mid
        if not nums or nums[i]!=target:
            return res
        res[0] = i
        j = len(nums)-1
        while i<j:
            mid = (i+j)/2+1
            if nums[mid] > target:
                j = mid - 1
            else:
                i = mid
        res[1] = i
        return res
