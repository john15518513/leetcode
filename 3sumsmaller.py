class Solution(object):
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) <3: # deal with special input
            return 0
        elif len(nums) == 3:
            if sum(nums) < target:
                return 1


        nums = sorted(nums) # sorted, O(nlgn)
        count = 0

        for i in range(len(nums) -2):
            j = i+1
            k = len(nums) -1 # hence i < j < k

            while j<k: # if not cross line
                temp_sum = nums[i] + nums[j] + nums[k]
                if temp_sum-target < 0:
                    count += k-j
                    j += 1
                if temp_sum-target >= 0: # which means we need smaller sum, move k backward, remember we sort the array
                    k -= 1
            
                    
        return count
