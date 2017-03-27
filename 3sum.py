class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <3: # deal with special input
            return []
        elif len(nums) == 3:
            if sum(nums) == 0:
                return [sorted(nums)]


        nums = sorted(nums) # sorted, O(nlgn)
        ans = []

        for i in range(len(nums) -2):
            j = i+1
            k = len(nums) -1 # hence i < j < k

            while j<k: # if not cross line
                temp_sum = nums[i] + nums[j] + nums[k]
                if temp_sum == 0:
                    ans.append((nums[i], nums[j], nums[k]))

                if temp_sum > 0: # which means we need smaller sum, move k backward, remember we sort the array
                    k -= 1
                else:
                    j += 1

        return list(set(ans)) # I bet this is not the best way to eliminate duplicate solutions

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3 or (len(nums) == 3 and sum(nums) != 0):
            return []
        nums.sort()
        res = []
        #print "hi"
        for i in xrange(len(nums)-2):
            if i == 0 or nums[i]!=nums[i-1]:
                j, k = i+1, len(nums)-1
                while j<k:
                    tmp = nums[i]+nums[j]+nums[k]
                    if tmp == 0:
                        res.append((nums[i], nums[j], nums[k]))
                        while j < k and nums[j] == nums[j+1]:
                            j += 1
                        while j < k and nums[k] == nums[k-1]:
                            k -= 1
                        j += 1
                        k -= 1
                    elif tmp > 0:
                        k -= 1
                    else:
                        j += 1
        return list(set(res))
            
