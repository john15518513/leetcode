class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        if (numRows == 0) return res;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) res[i].push_back(1);
            else {
                res[i].push_back(1);
                for (int j = 1; j < res[i-1].size(); j++) {
                    res[i].push_back(res[i-1][j-1]+res[i-1][j]);
                }
                res[i].push_back(1);
            }
        }
        return res;
    }
};
