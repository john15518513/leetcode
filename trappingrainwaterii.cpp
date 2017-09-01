class Cell {
public:
    int row;
    int col;
    int height;
    Cell(int x, int y, int z): row(x), col(y), height(z) {}
};
class Solution {
    struct cmp {
        bool operator()(const Cell* a, const Cell* b) {
            return a->height > b->height;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Cell*, vector<Cell*>, cmp> pq; 
        if (heightMap.size() == 0 || heightMap[0].size() == 0) return 0;
        vector<vector<bool>> visited(heightMap.size(), vector<bool>(heightMap[0].size(), false));
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int m = heightMap.size(), n = heightMap[0].size();
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            pq.push(new Cell(i, 0, heightMap[i][0]));
            pq.push(new Cell(i, n - 1, heightMap[i][n - 1])); 
        }
        for (int i = 0; i < n; i++) {
            visited[0][i] = true;
            visited[m - 1][i] = true;
            pq.push(new Cell(0, i, heightMap[0][i]));
            pq.push(new Cell(m - 1, i, heightMap[m - 1][i]));
        }
        int res = 0;
        while (!pq.empty()) {
            Cell* cell = pq.top();
            pq.pop();
            for (auto &e: dir) {
                int row = cell->row + e.first;
                int col = cell->col + e.second;
                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    visited[row][col] = true;
                    res += max(0, cell->height - heightMap[row][col]);
                    pq.push(new Cell(row, col, max(heightMap[row][col], cell->height)));
                }
            }
        }
        return res;
        
    }
    
};
