class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = nums[i] + dp[i-1][1];
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp.back().front(), dp.back().back());
    }
};
