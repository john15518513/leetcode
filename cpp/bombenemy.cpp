class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int>(n, 0));
        int rowhits = 0;
        vector<int> colhits(n, 0);
        int maxVal = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) { 
                if (!j || grid[i][j-1] == 'W') {
                    rowhits = 0;
                    for (int k = j; k < n and grid[i][k]!='W'; k++) rowhits += grid[i][k] == 'E'? 1:0;
                }
                if (!i || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k = i; k < m and grid[k][j] != 'W'; k++) colhits[j] += grid[k][j] == 'E'? 1:0;
                }
                if (grid[i][j] == '0') maxVal = max(maxVal, rowhits+colhits[j]);
            }
        }
        return maxVal;
    }
};
