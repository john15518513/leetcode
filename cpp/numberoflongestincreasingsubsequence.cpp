class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<pair<int, int>> dp(nums.size(), make_pair(1, 1));
        int max_len = 1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <i ; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1) dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if(max_len == dp[i].first) res += dp[i].second;
            if(max_len < dp[i].first){
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }
};
