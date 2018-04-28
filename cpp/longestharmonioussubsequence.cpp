class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> map;
        for (auto &n: nums) {
            map[n]++;
        }
        int maxV = 0;
        for (std::map<int,int>::iterator it = map.begin(); it != map.end(); it++) {
            auto next = it;
            next++;
            if (next != map.end() and next->first-it->first == 1) maxV = max(maxV, it->second+next->second);
        }
        return maxV;
    }
};
