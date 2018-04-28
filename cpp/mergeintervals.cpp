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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return a.start < b.start;});
        vector<Interval> result;
        for (int i = 0; i < intervals.size(); i++) {
            if (result.empty()) {
                result.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].start > result.back().end) result.push_back(intervals[i]);
            else{
                if (intervals[i].end > result.back().end) result.back().end = intervals[i].end;
            }
        }
        return result;
    }
};
