class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto &row: ops) {
            m = min(m, row[0]);
            n = min(n, row[1]);
        }
        return m*n;
    }
};
