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
    struct cmp {
        bool operator()(const Interval a, const Interval b) {
            return a.end < b.end;  
        }
    };
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp());
        int end = intervals[0].end;
        int maxCount = 1;
        //cout << "hi" << endl;
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i].start) {
                maxCount++;
                end = intervals[i].end;
            }
        }
        return intervals.size() - maxCount; 
    }
};
