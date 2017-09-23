class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() or matrix[0].empty()) return false;
        vector<int> row;
        for (int i = 0; i < matrix.size(); i++) row.push_back(matrix[i][0]);
        int r = lower_bound(row.begin(), row.end(), target) - row.begin();
        if (row[r] > target and r-1 < 0) return false;
        if (row[r] == target) return true;
        r -= 1;
        int c = lower_bound(matrix[r].begin(), matrix[r].end(), target) - matrix[r].begin();
        if (matrix[r][c] == target) return true;
        else return false;
        
        
    }
};
