class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]? 1:-1;
            if (map.find(sum) == map.end()) map[sum] = i;
            if (sum == 0) maxLen = i + 1;
            else if (map.find(sum) != map.end()) maxLen = max(maxLen, i-map[sum]);
        }
        return maxLen;
    }
};
