class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> moves = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        int len = N;
        vector<vector<double>> dp0(N, vector<double>(N, 1));
        for(int l = 0; l < K; l++) {
            vector<vector<double>> dp1(N, vector<double>(N, 0));
            for(int i = 0; i < len; i++) {
                for(int j = 0; j < len; j++) {
                    for(auto &move : moves) {
                        int row = i + move[0];
                        int col = j + move[1];
                        if(isLegal(row, col, len)) dp1[i][j] += dp0[row][col];
                    }
                }
            }
            dp0 = dp1;
        }
        return dp0[r][c] / pow(8, K);
    }
    bool isLegal(int r, int c, int len) {
        if (r < 0 || c < 0 || r >= len || c >= len) return false;
        return true;
    }
    
};
