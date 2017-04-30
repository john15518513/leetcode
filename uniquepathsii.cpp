class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1, 0));
        dp[0][1] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
                }
            }
        }
        return dp.back().back();
    }
};
