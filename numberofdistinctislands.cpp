class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    string path = "";
                    dfs(grid, i, j, path, 'S');
                    //cout << path << endl;
                    pool.insert(path);
                }
            }
        }
        
        return pool.size();
    }
    void dfs(vector<vector<int>>& grid, int i, int j, string& path, char dir) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || 0 == grid[i][j]) return;
        path.push_back(dir);
        grid[i][j] = 0;
        dfs(grid, i-1, j, path, 'U');
        dfs(grid, i+1, j, path, 'D');
        dfs(grid, i, j-1, path, 'L');
        dfs(grid, i, j+1, path, 'R');
        path.push_back('#');
        
    }
    unordered_set<string> pool;
};
