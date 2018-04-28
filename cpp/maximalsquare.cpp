class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxVal = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxVal = max(maxVal, dp[0][i]);
        }
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxVal = max(maxVal, dp[i][0]);
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    cout << "in";
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                    maxVal = max(maxVal, dp[i][j]);
                }
            }
        }
        return maxVal*maxVal;
        
    }
};
