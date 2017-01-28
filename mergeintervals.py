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
        while len(intervals):
            range = intervals.pop(0)
            for i in res:
                if range.start <= i.end:
                    i.end = range.end if range.end > i.end else i.end
                    break;
            else:
                res.append(range)
        return res
