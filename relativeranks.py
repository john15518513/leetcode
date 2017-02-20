class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        tmp = []
        for i in xrange(len(nums)):
            tmp.append([nums[i], i])
        tmp = sorted(tmp, key=lambda x: x[0], reverse=True)
        count = 1
        res = [None for _ in xrange(len(nums))]
        for i in tmp:
            if count > 3:
                target = str(count)
            elif count == 3:
                target = "Bronze Medal"
            elif count == 2:
                target = "Silver Medal"
            else:
                target = "Gold Medal"
                
            res[i[1]] = target
            count += 1
        return res
        
