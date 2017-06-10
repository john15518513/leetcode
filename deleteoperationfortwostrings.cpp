class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.length()+1, vector<int>(word1.length()+1, 0));
        for (int i = 1; i < word2.length()+1; i++) {
            for (int j = 1; j < word1.length()+1; j++) {
                if (word1[j-1] == word2[i-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return word1.length()+word2.length()-2*dp.back().back();
    }
};
