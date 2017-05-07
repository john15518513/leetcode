class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> unionSet(n, -1);
        for (auto &e: edges) {
            int x = find(unionSet, e.first);
            int y = find(unionSet, e.second);
            
            if (x == y) return false;
            unionSet[x] = y;
        }
        return n-1 == edges.size();
    }
    int find(vector<int> &unionSet, int e) {
        if (unionSet[e] == -1) return e;
        return find(unionSet, unionSet[e]);
    }  
};
