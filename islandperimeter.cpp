class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int iCount = 0;
        int nCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    iCount++;
                    if(j+1 < grid[0].size() and grid[i][j+1] == 1) nCount++;
                    if(i+1 < grid.size() and grid[i+1][j] == 1) nCount++;
                }
            }
        }
        return iCount*4-nCount*2;
    }
};
