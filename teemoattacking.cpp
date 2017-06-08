class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int pe = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            res += duration - (timeSeries[i] < pe)*(pe - timeSeries[i]);
            pe = timeSeries[i] + duration;
        }
        return res;
    }
};
