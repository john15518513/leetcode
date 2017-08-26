class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (!triangle.size()) return 0;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) triangle[i][j] += triangle[i-1].front();
                else if (j == triangle[i].size()-1) triangle[i][j] += triangle[i-1].back();
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        /*for (auto &r: triangle) {
            for (auto &c: r) {cout << c << " ";}
            cout << endl;
        }*/
        int minPath = INT_MAX;
        for (auto &e: triangle.back()) minPath = min(minPath, e);
        return minPath;
    }
};
