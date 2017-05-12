class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int count = 0;
        for (auto &e: edges) {
            adjList[e.first].push_front(e.second);
            adjList[e.second].push_front(e.first);
        }
        //cout << "countComponent" << endl;
        for (int i = 0; i < n; i++) {
            //cout << i << endl;
            if (vis.count(i) == 0) {
                count++;
                dfs(i);
            }
        }
        return count;
        
    }
    void dfs(int node) {
        if (vis.count(node) != 0) return;
        vis.insert(node);
        for (auto &n: adjList[node]) {
            //cout << node << " " << n << endl;
            dfs(n);
        }
    }
private:
    unordered_set<int> vis;
    unordered_map<int, list<int>> adjList;
};
