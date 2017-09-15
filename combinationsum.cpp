class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        dfs(candidates, target, path, res);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& res) {
        if ( target < 0) return;
        if (target == 0) {
            vector<int> tmp = path;
            sort(tmp.begin(), tmp.end());
            if (vis.find(tmp) == vis.end()) {
                vis.insert(tmp);
                res.push_back(path);
            }
            return;
        }
        for (int index = 0; index < candidates.size(); index++) {
            path.push_back(candidates[index]);
            dfs(candidates, target-candidates[index], path, res);
            path.pop_back();
        }
    }
    set<vector<int>> vis;
};
