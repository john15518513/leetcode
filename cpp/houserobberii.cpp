class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = nums[0];
        for (int i = 1; i < n-1; i++) {
            dp[i][0] = dp[i-1][1]+nums[i];
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }
        int c1 = max(dp[n-2][0], dp[n-2][1]);
        dp[1][0] = nums[1];
        dp[1][1] = 0;
        for (int i = 2; i < n; i++) {
            dp[i][0] = dp[i-1][1]+nums[i];
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }
        int c2 = max(dp[n-1][0], dp[n-1][1]);
        return max(c1, c2);
    }
};
