class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<vector<int>> dp(costs.size(), vector<int>(3, 0));
        dp[0] = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            for (int j = 0; j < costs[0].size(); j++) {
                dp[i][j] = costs[i][j]+min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        return min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};
