class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # find the number of rotation
        l = 0
        h = len(nums)-1
        while l < h:
            mid = (l+h)/2
            if nums[mid] > nums[h]:
                l = mid+1
            else:
                h = mid
        
        rot = l
        l = 0
        n = len(nums)
        h = len(nums)-1
        while l <= h:
            mid = (l+h)/2
            if nums[(mid+rot)%n] == target:
                return (mid+rot)%n
            elif nums[(mid+rot)%n] > target:
                h = mid-1
            else:
                l = mid+1
        return -1
