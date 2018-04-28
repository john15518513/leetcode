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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> map;
        for (auto &i: intervals) {map[i.start]++; map[i.end]--;}
        int room = 0, maxRoom = 0;
        for (auto &i: map) {
            maxRoom = max(maxRoom, room += i.second);
        }
        return maxRoom;
        
    }
};
