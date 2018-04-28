class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                }
            }
        }
        return maxNum;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 or j < 0 or i == grid.size() or j == grid[0].size() or grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        count++;
        maxNum = max(maxNum, count);
        dfs(grid, i-1, j, count);
        dfs(grid, i+1, j, count);
        dfs(grid, i, j-1, count);
        dfs(grid, i, j+1, count);
    }
    int maxNum = 0;
};
