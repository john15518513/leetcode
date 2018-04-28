class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> numCount;
        size_t degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            numCount[nums[i]].push_back(i);
            degree = max(degree, numCount[nums[i]].size());
        }
        int res = nums.size();
        for (auto &it: numCount) {
            if (it.second.size() == degree) {
                res = min(res, it.second.back() - it.second.front() + 1);
            }
        }
        return res;
    }
};
