class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, path, 0, target, res);
        return res;
    }
    void dfs(vector<int>& candidates, vector<int> &path, int index, int target, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            if (i && candidates[i] == candidates[i-1] && i > index) continue;
            path.push_back(candidates[i]);
            dfs(candidates, path, i+1, target-candidates[i], res);
            path.pop_back();
        }
    }
    
};
