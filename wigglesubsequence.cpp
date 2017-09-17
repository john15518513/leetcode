class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> interval;
        vector<int> dp;
        for (int i = 1; i < nums.size(); i++) dp.push_back(nums[i]-nums[i-1]? 1:0);
        int maxV = 0;
        for (int i = 1; i < nums.size(); i++) interval.push_back(nums[i]-nums[i-1]);
        for (int i = 1; i < interval.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (interval[i]*interval[j] < 0) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxV = max(maxV, dp[i]);
        }
        return maxV+1;
    }
};
