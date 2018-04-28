class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 0 or not nums:
            return 0
        dic = {}
        for i in nums:
            dic[i] = dic.get(i, 0) + 1
        cnt = 0
        for key in dic:
            if k == 0:
                if dic[key] >= 2:
                    cnt += 1
            elif key+k in dic:
                cnt += 1
        return cnt
                
