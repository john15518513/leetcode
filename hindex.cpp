class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> dp(citations.size()+1, 0);
        for (auto &c: citations) {
            if (c >= citations.size()) dp.back()++;
            else dp[c]++;
        }
        int cur = 0;
        for (int i = dp.size()-1; i >= 0; i--) {
            cur += dp[i];
            if (cur >= i) return i;
        }
        return 0;
    }
};
