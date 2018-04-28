class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int minV = INT_MAX;
        vector<pair<int, int>> grids;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1) grids.push_back(make_pair(i,j));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                    int total = 0;
                    for (auto &e : grids) {
                        total += manhattanDistance(e, make_pair(i,j));
                    }
                    minV = min(minV, total);
            }
        return minV;
    }
    int manhattanDistance(pair<int, int> a, pair<int, int> b) {
        return abs(a.first-b.first) + abs(a.second-b.second);
    }
};
