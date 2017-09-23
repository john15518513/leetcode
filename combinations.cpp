class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, res, path, k, n);
        return res;
        
    }
    void dfs(int i, vector<vector<int>>& res, vector<int>& path, int k, int n) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int j = i; j <= n; j++) {
            path.push_back(j);
            dfs(j+1, res, path, k, n);
            path.pop_back();
        }
    }
};
