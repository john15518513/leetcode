class Solution {
    
    int curMax;
    
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) {
                    curMax = 0;
                    dfs(grid, i, j);
                    System.out.println(curMax);
                    maxArea = Math.max(maxArea, curMax);
                }
            }
        }
        
        return maxArea;
    }
    
    private void dfs(int[][] grid, int i, int j) {
        
        if (i < 0 || i == grid.length || j < 0 || j == grid[i].length || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        curMax += 1;
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        
    }
    
}
