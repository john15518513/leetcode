class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        if (matrix.empty() or matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        //int index = 0;
        int rowBegin = 0;
        int rowEnd = m-1;
        int colBegin = 0;
        int colEnd = n-1;
        //pair<int, int> pos = {0, 0};
        while (res.size() < m*n) {
            for (int j = colBegin; j <= colEnd; j ++) {
                res.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;
            
            // Traverse Down
            for (int j = rowBegin; j <= rowEnd; j ++) {
                res.push_back(matrix[j][colEnd]);
            }
            colEnd--;
            
            if (rowBegin <= rowEnd) {
                // Traverse Left
                for (int j = colEnd; j >= colBegin; j --) {
                    res.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;
            
            if (colBegin <= colEnd) {
                // Traver Up
                for (int j = rowEnd; j >= rowBegin; j --) {
                    res.push_back(matrix[j][colBegin]);
                }
            }
            colBegin ++;
        }
        return res;
    }
};
