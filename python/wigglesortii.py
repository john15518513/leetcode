class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        mid = len(nums)/2
        if len(nums)%2 == 1:
           mid = mid + 1
        list1 = nums[:mid][::-1]
        list2 = nums[mid:][::-1]
        res = []
        i = 0
        while list1 and list2:
            nums[i] = list1.pop(0)
            i += 1
            nums[i] = list2.pop(0)
            i += 1
        if list1:
            nums[i] = list1.pop(0)
        
        
        
            
