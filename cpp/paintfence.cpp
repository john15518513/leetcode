class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 or k == 0) return 0;
        if (n == 1) return k;
        vector<vector<int>> dp(n, vector<int>(2, k));
        dp[1][1] = k*(k-1);
        for (int i = 2; i < n; i++) {
            //same
            dp[i][0] = dp[i-1][1];
            //diff
            dp[i][1] = dp[i-1][1]*(k-1) + dp[i-1][0]*(k-1);
            
        }
        return dp.back()[0]+dp.back()[1];
    }
};
