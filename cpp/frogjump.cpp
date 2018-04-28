class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> map;
        for (int i = 0; i < stones.size(); i++) map[stones[i]] = unordered_set<int> {};
        map[stones.front()].insert(1);
        for (int i = 0; i < stones.size()-1; i++) {
            for (auto &e: map[stones[i]]) {
                int reach = stones[i]+e;
                if (map.find(reach) != map.end()) {
                    if (e-1>0) 
                        map[reach].insert(e-1);
                    map[reach].insert(e);
                    map[reach].insert(e+1);
                }
                if (map[stones.back()].size() != 0) return true;
            }
        }
        return false;
    }
};
