class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        curMin = float('inf')
        cur = nums[0] + nums[1] + nums[2]
        for i in xrange(len(nums)-2):
            j = i+1
            k = len(nums)-1
            while j<k:
                tmp = nums[i] + nums[j] + nums[k]
                if tmp == target:
                    return target
                elif tmp < target:
                    j += 1
                else:
                    k -=1
                if abs(target-tmp) < curMin:
                    curMin = abs(target-tmp)
                    cur = tmp
        return cur
