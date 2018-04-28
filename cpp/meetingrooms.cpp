/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals.front().end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < end ) return false;
            end = intervals[i].end;
        }
        return true;
    }
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
