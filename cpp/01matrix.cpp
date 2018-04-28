class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> que;
        for (auto i = 0; i < m; i++)
            for(auto j = 0; j < n; j++) {
                if (matrix[i][j] == 0) que.push(make_pair(i,j));
                else matrix[i][j] = INT_MAX;
            }
        vector<pair<int,int>> dir({{-1,0}, {1,0}, {0,-1}, {0,1}});
        while (!que.empty()) {
            pair<int, int> cell = que.front();
            que.pop();
            for (auto &d: dir) {
                int r = cell.first + d.first;
                int c = cell.second + d.second;
                if (r < 0 || r >= m || c < 0 || c >= n || 
                    matrix[r][c] <= matrix[cell.first][cell.second] + 1) continue;
                que.push(make_pair(r,c));
                matrix[r][c] = matrix[cell.first][cell.second]+1;
            }
        }
        return matrix;
        
    }
};
