
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for (int i = 0; i < ppid.size(); i++) {
            map[ppid[i]].insert(pid[i]);
        }
        dfs(kill);
        return res;
    }
    void dfs(int kill) {
        res.push_back(kill);
        for (auto &e: map[kill]) {
            dfs(e);
        }
    }
private:
    unordered_map<int, unordered_set<int>> map;
    vector<int> res;
};
