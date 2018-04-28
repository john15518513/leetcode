class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (map.find(sum) == map.end()) map[sum] = i;
            if (sum == k) maxLen = i+1;
            else if (map.find(sum-k) != map.end()) maxLen = max(maxLen, i-map[sum-k]);
        }
        return maxLen;
    }
    
};
