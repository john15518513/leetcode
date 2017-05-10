class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S? 0: (sum+S)&1? 0: subsetSum(nums, (sum+S)>>1);
    }
    
    int subsetSum(vector<int> &nums, int S) {
        vector<int> dp(S+1, 0);
        dp[0] = 1;
        for (auto &n: nums) {
            for (int i=S; i>=n; i--) {
                dp[i] += dp[i-n];
            }
        }
        return dp.back();
    }
};
