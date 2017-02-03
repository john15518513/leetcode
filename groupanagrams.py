class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dict = {}
        for w in strs:
            m = tuple(sorted(w))
            dict[m] = dict.get(m, [])+[w]
            
        return dict.values()
