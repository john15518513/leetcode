class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> unionSet(2001, -1);
        vector<vector<int>> candidates;
        for(auto &e: edges) {
            auto x = find(unionSet, e[0]);
            auto y = find(unionSet, e[1]);
            if (x == y) candidates.push_back(e);
            else unionSet[x] = y;
        }
        return candidates.back();       
    }
    int find(vector<int>& unionSet, int p) {
        if (unionSet[p] == -1) return p;
        return find(unionSet, unionSet[p]);
    }
};
