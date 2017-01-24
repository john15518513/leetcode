class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        import collections
        c = collections.Counter(nums)
        c = sorted(c.items(), key=lambda x: x[1], reverse=True)
        return [x[0] for x in c[:k]]
