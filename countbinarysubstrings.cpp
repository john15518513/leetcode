class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1;
        int i;
        vector<int> dp;
        for (i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) {
                dp.push_back(count);
                count = 1;
            }
            else count++;
        }
        dp.push_back(count);
        int res = 0;
        for (int i = 1; i < dp.size(); i++) {
            //cout << dp[i] << endl;
            res += min(dp[i], dp[i-1]);
        }
        return res;
    }
};
