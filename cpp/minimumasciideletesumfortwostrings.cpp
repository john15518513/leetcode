class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int ans = 0;
                ans = max(dp[i-1][j], dp[i][j-1]);
                if (s1[i-1] == s2[j-1]) ans = max(ans, s1[i-1]+dp[i-1][j-1]);
                dp[i][j] = ans;
            }
        }
        int res = 0;
        for (auto &c : s1) res += c;
        for (auto &c : s2) res += c;
        res -= 2*dp[m][n];
        return res;
    }
};
