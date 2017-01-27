class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if len(grid) == 0:
            return 0
        self.m, self.n = len(grid), len(grid[0])
        count = 0
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count += 1
        return count
    def dfs(self, grid, i, j):
        if i<0 or j<0 or i>=self.m or j >= self.n or grid[i][j] != '1':
            return
        grid[i][j] = '0'
        self.dfs(grid, i-1, j)
        self.dfs(grid, i+1, j)
        self.dfs(grid, i, j-1)
        self.dfs(grid, i, j+1)
