class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> vis(M.size(), 0);
        int count = 0;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                dfs(M, vis, i);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>> &M, vector<int> &vis, int i) {
        vis[i] = 1;
        for (int j = 0; j < vis.size(); j++) {
            if (M[i][j] == 1 and vis[j] == 0) {
                dfs(M, vis, j);
            }
        }
    }
};
