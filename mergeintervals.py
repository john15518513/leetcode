# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
	intervals = sorted(intervals, key=lambda x: x.start)
        res = []
        while intervals:
            i = intervals.pop(0)
            for r in reversed(res):
                if i.start <= r.end:
                    r.end = r.end if i.end <= r.end else i.end
                    break
            else:
                res.append(i)
            
        return res
